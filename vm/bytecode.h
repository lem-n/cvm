#ifndef VM_BYTECODE_H
#define VM_BYTECODE_H

#define BYTECODE_COUNT 25

enum opcode {
    OP_HALT,        // stop program execution
    OP_NOOP,        // blank op code, does nothing (skips to next instruction)
    OP_IADD,        // integer add
    OP_ISUB,        // integer subtract
    OP_IMUL,        // ingeter multiply
    OP_IDIV,        // integer division
    OP_CMP,         // comparisson
    OP_INC,         // increment value at top of stack by 1
    OP_DEC,         // decrement value at top of stack by 1
    OP_ILT,         // integer less than
    OP_IEQ,         // integer equals
    OP_JMP,         // jump to address
    OP_JMPZ,        // jump if zero
    OP_JMPEQ,       // jump if equal
    OP_JMPNEQ,      // jump if not equal
    OP_JMPNZ,       // jump if not zero
    OP_ICONST,      // push integer
    OP_LOAD,        // load from local
    OP_GLOAD,       // load from global
    OP_POP,         // discard top of stack
    OP_STORE,       // store in local
    OP_GSTORE,      // store in global
    OP_IPRINT,      // print top of stack (integer)
    OP_CPRINT,      // print top of stack (character)
    OP_GETC,        // get character from stdin and store at the top of stack
};

typedef struct _bytecode_instr {
    char* opname;
    int opcode;
    int argc;
} bytecode_instr;

bytecode_instr opcodes[BYTECODE_COUNT];

#endif  // VM_BYTECODE_H