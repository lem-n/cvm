#include "bytecode.h"

const bytecode_instr opcodes[BYTECODE_COUNT] = {
    {"HALT", OP_HALT, 0},     {"NOOP", OP_NOOP, 0},     {"IADD", OP_IADD, 0},
    {"ISUB", OP_ISUB, 0},     {"IMUL", OP_IMUL, 0},     {"IDIV", OP_IDIV, 0},
    {"CMP", OP_CMP, 1},       {"INC", OP_INC, 0},       {"DEC", OP_DEC, 0},
    {"ILT", OP_ILT, 0},       {"IEQ", OP_IEQ, 0},       {"JMP", OP_JMP, 1},
    {"JMPZ", OP_JMPZ, 1},     {"JMPNZ", OP_JMPNZ, 1},   {"JMPEQ", OP_JMPEQ, 1},
    {"JMPNEQ", OP_JMPNEQ, 1}, {"ICONST", OP_ICONST, 1}, {"LOAD", OP_LOAD, 1},
    {"GLOAD", OP_GLOAD, 1},   {"POP", OP_POP, 0},       {"STORE", OP_STORE, 1},
    {"GSTORE", OP_GSTORE, 1}, {"IPRINT", OP_IPRINT, 0}, {"CPRINT", OP_CPRINT, 0},
    {"GETC", OP_GETC, 1},
};
