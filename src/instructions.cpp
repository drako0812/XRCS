#include "instructions.hpp"

namespace XRCS::cpu {
    DECLI(NOP) {}
    DECLI(RST) {}
    DECLI(BRK) {}
    DECLI(CPU) {}

    DECLI(INC) {}
    DECLI(DEC) {}
    DECLI(ICC) {}
    DECLI(DCB) {}
    DECLI(ADD) {}
    DECLI(SUB) {}
    DECLI(MUL) {}
    DECLI(DIV) {}
    DECLI(MOD) {}
    DECLI(ADC) {}
    DECLI(SBB) {}
    DECLI(MLS) {}
    DECLI(DVS) {}
    DECLI(MDS) {}

    DECLI(AND) {}
    DECLI(OR) {}
    DECLI(XOR) {}
    DECLI(EQ) {}
    DECLI(NEQ) {}
    DECLI(LT) {}
    DECLI(LTE) {}
    DECLI(GT) {}
    DECLI(GTE) {}
    DECLI(ZERO) {}
    DECLI(NZERO) {}

    DECLI(BAND) {}
    DECLI(BOR) {}
    DECLI(BXOR) {}
    DECLI(BNOT) {}
    DECLI(BSET) {}
    DECLI(BRST) {}
    DECLI(BTST) {}

    DECLI(PUSH_i) {}
    DECLI(PUSH_a) {}
    DECLI(POP) {}
    DECLI(POP_a) {}
    DECLI(SST) {}
    DECLI(SSTX) {}
    DECLI(POPN) {}
    DECLI(POP_p) {}
    DECLI(TOP_a) {}
    DECLI(TOP_p) {}
    DECLI(PUSH_p) {}

    DECLI(JMP) {}
    DECLI(JPS) {}
    DECLI(JPZ) {}
    DECLI(JNZ) {}
    DECLI(CALL) {}
    DECLI(CALLS) {}
    DECLI(CALLZ) {}
    DECLI(CALNZ) {}

    DECLI(OUT) {}
    DECLI(IN) {}

    DECLI(INC24) {}
    DECLI(ADD24) {}
    DECLI(GTE24) {}
    DECLI(PUSH24_a) {}
    DECLI(POP24_a) {}
    DECLI(POP24_p) {}
    DECLI(TOP24_a) {}
    DECLI(TOP24_p) {}
    DECLI(PUSH24_p) {}

} // namespace XRCS::cpu
