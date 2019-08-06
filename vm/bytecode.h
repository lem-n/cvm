#ifndef VM_BYTECODE_H
#define VM_BYTECODE_H  

enum opcode {
    OPCODE_HALT,        // stop program execution
    OPCODE_IADD,        // integer add
    OPCODE_ISUB,        // integer subtract
    OPCODE_IMUL,        // ingeter multiply
    OPCODE_IDIV,        // integer division
    OPCODE_ILT,         // integer less than
    OPCODE_IEQ,         // integer equals
    OPCODE_JMP,         // jump to address
    OPCODE_JMPZ,        // jump if zero
    OPCODE_JMPNZ,       // jump if not zero
    OPCODE_ICONST,      // push integer
    OPCODE_LOAD,        // load from local
    OPCODE_GLOAD,       // load from global
    OPCODE_POP,         // discard top of stack
    OPCODE_STORE,       // store in local
    OPCODE_GSTORE,      // store in global
    OPCODE_PRINT        // print top of stack
};

typedef struct {
    char* opname;
    int opcode;
    int argc;
} bytecode_instr;

bytecode_instr opcodes[17];

#endif  // VM_BYTECODE_H