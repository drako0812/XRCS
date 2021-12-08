#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <functional>
#include <string>
#include <vector>

#include "utility.hpp"

#ifndef MEMORY_DEBUG_FILL
#    define MEMORY_DEBUG_FILL 0x00
#endif

namespace XRCS::mem {

    template<std::size_t Bytes> class Memory {
      private:
        std::array<std::uint8_t, Bytes> data;

      public:
        inline Memory();
        inline void LoadAt(std::size_t address, std::size_t max_size, const std::filesystem::path & file_path);

        inline std::uint8_t  AtByte(std::size_t address) const;
        inline std::uint16_t AtWord(std::size_t address) const;
        inline std::uint32_t AtAddr(std::size_t address) const;

        inline void AtByte(std::size_t address, std::uint8_t value);
        inline void AtWord(std::size_t address, std::uint16_t value);
        inline void AtAddr(std::size_t address, std::uint32_t value);
    };

    constexpr std::size_t MemoryBytes = 0x1000000;

    using XRCSMemory = Memory<MemoryBytes>;

    template<std::size_t Bytes> Memory<Bytes>::Memory() {
        std::uint8_t val;

#ifdef _DEBUG
        val = MEMORY_DEBUG_FILL;
#else
        val = 0x00;
#endif

        memset(data.data(), val, data.size());
    }

    template<std::size_t Bytes>
    void Memory<Bytes>::LoadAt(std::size_t address, std::size_t max_size, const std::filesystem::path & file_path) {
        Assert(std::filesystem::exists(file_path), "Memory::LoadAt: file_path does not exist");
        Assert(!std::filesystem::is_directory(file_path), "Memory::LoadAt: file_path must not be a directory");

        auto fsize = std::filesystem::file_size(file_path);

        std::ifstream infile(file_path, std::ios::in | std::ios::binary);
        DEFER([&]() {
            infile.close();
            std::cout << "Memory::LoadAt: infile closed\n";
        });
        Assert((bool)infile, "Memory::LoadAt: unable to load file_path");

        auto bytes_to_read = std::min(max_size, fsize);

        infile.read((char *)data.data(), bytes_to_read);
    }

    template<std::size_t Bytes> std::uint8_t Memory<Bytes>::AtByte(std::size_t address) const {
        address = address % Bytes;
        return data.at(address);
    }

    template<std::size_t Bytes> std::uint16_t Memory<Bytes>::AtWord(std::size_t address) const {
        address            = address % Bytes;
        std::uint16_t low  = AtByte(address);
        std::uint16_t high = AtByte(address + 1);
        return (high << 8) | low;
    }

    template<std::size_t Bytes> std::uint32_t Memory<Bytes>::AtAddr(std::size_t address) const {
        address            = address % Bytes;
        std::uint32_t low  = AtByte(address);
        std::uint32_t mid  = AtByte(address + 1);
        std::uint32_t high = AtByte(address + 2);
        return (high << 16) | (mid << 8) | low;
    }

    template<std::size_t Bytes> void Memory<Bytes>::AtByte(std::size_t address, std::uint8_t value) {
        address          = address % Bytes;
        data.at(address) = value;
    }

    template<std::size_t Bytes> void Memory<Bytes>::AtWord(std::size_t address, std::uint16_t value) {
        address = address % Bytes;
        AtByte(address, value & 0x00FF);
        AtByte(address + 1, value >> 8);
    }

    template<std::size_t Bytes> void Memory<Bytes>::AtAddr(std::size_t address, std::uint32_t value) {
        address = address % Bytes;
        AtByte(address, value & 0x0000FF);
        AtByte(address + 1, (value & 0x00FF00) >> 8);
        AtByte(address + 2, (value & 0xFF0000) >> 16);
    }

} // namespace XRCS::mem
