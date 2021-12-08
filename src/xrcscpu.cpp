#include "xrcscpu.hpp"
#include "instruction-table.hpp"

#include <format>

namespace XRCS::cpu {
    std::uint32_t Cpu::GetPC() const { return PC & 0x00FFFFFF; }

    std::uint32_t Cpu::GetSP() const { return SP & 0x00FFFFFF; }

    std::uint32_t Cpu::GetSS() const { return SS & 0x00FFFFFF; }

    void Cpu::SetPC(std::uint32_t value) { PC = value & 0x00FFFFFF; }

    void Cpu::SetSP(std::uint32_t value) { SP = value & 0x00FFFFFF; }

    void Cpu::SetSS(std::uint32_t value) { SS = value & 0x00FFFFFF; }

    void Cpu::Tick(XRCS::mem::XRCSMemory & mem) {
        Ticks--;
        if (Ticks < 0) {
            Ticks = 0;
            Execute(mem);
        }
    }

    void Cpu::Execute(XRCS::mem::XRCSMemory & mem) {
        // Get first byte of instruction
        auto inst1 = mem.AtByte(GetPC());

        switch (inst1) {
        case Opcode8::_EXT: {
            // Extended Instruction
            auto inst2 = mem.AtByte(GetPC() + 1);
            switch (inst2) {
            case OpcodeExtensions::ADDR: {
                auto inst3 = mem.AtByte(GetPC() + 2);
                ExecuteADDRInstruction((OpcodeADDR)inst3, mem);
                break;
            }
            default: Assert(false, std::format("Cpu::Excute: Invalid Opcode Extension Code \"{:x}\"", inst2)); break;
            }
            break;
        }
        default: ExecuteSimpleInstruction((Opcode8)inst1, mem); break;
        }
    }
} // namespace XRCS::cpu
