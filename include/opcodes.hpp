#pragma once

#include <cstdint>

namespace XRCS::cpu {

    enum Opcode8 : std::uint8_t {
        NOP = 0x00,
        RST,
        BRK,
        CPU,

        INC = 0x10,
        DEC,
        ICC,
        DCB,
        ADD,
        SUB,
        MUL,
        DIV,
        MOD,
        ADC,
        SBB,
        MLS,
        DVS,
        MDS,

        AND = 0x20,
        OR,
        XOR,
        EQ,
        NEQ,
        LT,
        LTE,
        GT,
        GTE,
        ZERO,
        NZERO,

        BAND = 0x30,
        BOR,
        BXOR,
        BNOT,
        BSET,
        BRST,
        BTST,

        PUSH_i = 0x40,
        PUSH_a,
        POP,
        POP_a,
        SST,
        SSTX,
        POPN,
        POP_p,
        TOP_a,
        TOP_p,
        PUSH_p,

        JMP = 0x50,
        JPS,
        JPZ,
        JNZ,
        CALL,
        CALLS,
        CALLZ,
        CALNZ,

        OUT = 0x60,
        IN,

        _EXT = 0xFF,
    };

    enum OpcodeExtensions : std::uint8_t {
        NONE = 0x00,
        WORD = 0x01,
        ADDR = 0x02,
    };

    enum OpcodeADDR : std::uint8_t {
        INC24    = 0x10,
        ADD24    = 0x14,
        GTE24    = 0x28,
        PUSH24_a = 0x41,
        POP24_a  = 0x43,
        POP24_p  = 0x47,
        TOP24_a  = 0x48,
        TOP24_p  = 0x49,
        PUSH24_p = 0x4A,
    };

} // namespace XRCS::cpu
