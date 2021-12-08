#pragma once

#include <map>

#include "instructions.hpp"
#include "opcodes.hpp"

#define TABLEI8(instruction__, size__) \
    std::make_pair(Opcode8::instruction__, InstructionTableEntry{size__, inst_##instruction__})
#define TABLEI24(instruction__, size__) \
    std::make_pair(OpcodeADDR::instruction__, InstructionTableEntry{size__, inst_##instruction__})

namespace XRCS::cpu {

    using InstructionFunction = decltype(inst_NOP) *;

    struct InstructionTableEntry {
        std::uint8_t        Size;
        InstructionFunction Function;
    };

    using InstructionTableMap = std::map<OpcodeExtensions, std::map<std::uint8_t, InstructionTableEntry>>;

    static inline InstructionTableMap InstructionTable = {
      {OpcodeExtensions::NONE,
       {TABLEI8(NOP, 1),    TABLEI8(RST, 1),    TABLEI8(BRK, 1),   TABLEI8(CPU, 1),

        TABLEI8(INC, 1),    TABLEI8(DEC, 1),    TABLEI8(ICC, 1),   TABLEI8(DCB, 1),   TABLEI8(ADD, 1),
        TABLEI8(SUB, 1),    TABLEI8(MUL, 1),    TABLEI8(DIV, 1),   TABLEI8(MOD, 1),   TABLEI8(ADC, 1),
        TABLEI8(SBB, 1),    TABLEI8(MLS, 1),    TABLEI8(DVS, 1),   TABLEI8(MDS, 1),

        TABLEI8(AND, 1),    TABLEI8(OR, 1),     TABLEI8(XOR, 1),   TABLEI8(EQ, 1),    TABLEI8(NEQ, 1),
        TABLEI8(LT, 1),     TABLEI8(LTE, 1),    TABLEI8(GT, 1),    TABLEI8(GTE, 1),   TABLEI8(ZERO, 1),
        TABLEI8(NZERO, 1),

        TABLEI8(BAND, 1),   TABLEI8(BOR, 1),    TABLEI8(BXOR, 1),  TABLEI8(BNOT, 1),  TABLEI8(BSET, 1),
        TABLEI8(BRST, 1),   TABLEI8(BTST, 1),

        TABLEI8(PUSH_i, 2), TABLEI8(PUSH_a, 4), TABLEI8(POP, 1),   TABLEI8(POP_a, 4), TABLEI8(SST, 7),
        TABLEI8(SSTX, 1),   TABLEI8(POPN, 4),   TABLEI8(POP_p, 4), TABLEI8(TOP_a, 4), TABLEI8(TOP_p, 4),
        TABLEI8(PUSH_p, 4),

        TABLEI8(JMP, 4),    TABLEI8(JPS, 1),    TABLEI8(JPZ, 4),   TABLEI8(JNZ, 4),   TABLEI8(CALL, 4),
        TABLIE8(CALLS, 1),  TABLEI8(CALLZ, 4),  TABLEI8(CALNZ, 4),

        TABLEI8(OUT, 1),    TABLEI8(IN, 1)}},
      {OpcodeExtensions::ADDR,
       {TABLEI24(INC24, 3),
        TABLEI24(ADD24, 3),

        TABLEI24(GTE24, 3),

        TABLEI24(PUSH24_a, 6),
        TABLEI24(POP24_a, 6),
        TABLEI24(POP24_p, 6),
        TABLEI24(TOP24_a, 6),
        TABLEI24(TOP24_p, 6),
        TABLEI24(PUSH24_p, 6)}}};

} // namespace XRCS::cpu
