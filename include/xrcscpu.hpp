#pragma once

#include "memory.hpp"
#include "opcodes.hpp"
#include <cstdint>

namespace XRCS::cpu {

    struct Cpu {
      private:
        std::uint32_t PC, SP, SS;

      public:
        std::int64_t Ticks;

        std::uint32_t GetPC() const;
        std::uint32_t GetSP() const;
        std::uint32_t GetSS() const;

        void SetPC(std::uint32_t value);
        void SetSP(std::uint32_t value);
        void SetSS(std::uint32_t value);

        void Tick(XRCS::mem::XRCSMemory & mem);
        void Execute(XRCS::mem::XRCSMemory & mem);

      protected:
        void ExecuteSimpleInstruction(Opcode8 opcode, XRCS::mem::XRCSMemory & mem);
        void ExecuteADDRInstruction(OpcodeADDR opcode, XRCS::mem::XRCSMemory & mem);
    };

} // namespace XRCS::cpu
