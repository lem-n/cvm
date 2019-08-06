#include "bytecode.h"

// Readable representation of bytecodes for execution tracing (then we can do opcodes[op - 1])
bytecode_instr opcodes[] = {
    {"HALT", OPCODE_HALT, 0},
    {"IADD", OPCODE_IADD, 0},
    {"ISUB", OPCODE_ISUB, 0},
    {"IMUL", OPCODE_IMUL, 0},
    {"IDIV", OPCODE_IDIV, 0},
    {"ILT", OPCODE_ILT, 0},
    {"IEQ", OPCODE_IEQ, 0},
    {"JMP", OPCODE_JMP, 1},
    {"JMPZ", OPCODE_JMPZ, 1},
    {"JMPNZ", OPCODE_JMPNZ, 1},
    {"ICONST", OPCODE_ICONST, 1},
    {"LOAD", OPCODE_LOAD, 1},
    {"GLOAD", OPCODE_GLOAD, 1},
    {"POP", OPCODE_POP, 0},
    {"STORE", OPCODE_STORE, 1},
    {"GSTORE", OPCODE_GSTORE, 1},
    {"PRINT", OPCODE_PRINT, 0}
};