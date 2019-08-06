#include "trace.h"

void trace_op(int op, int ip, int code[]) {
    bytecode_instr instr = opcodes[op];

    printf("%04d: %s", ip, instr.opname);
    if (instr.argc > 0) {
        for (int i = 1; i <= instr.argc; ++i) {
            if (i == instr.argc)
                printf(" %d", code[ip + i]);
            else
                printf(" %d,", code[ip + i]);
        }
    }
}

void trace_stack(int stack[], size_t stack_size) {
    printf("STACK [");

    int show = stack_size < 10 ? (int)stack_size : 10;
    for (int i = 0; i < show; ++i) {
        if (i == 9)
            printf(" %d", stack[i]);
        else
            printf(" %d,", stack[i]);
    }
    printf(" ]");
}

void trace_memory(int memory[], size_t memory_size) {
    printf("MEM:  [");

    int show = memory_size < 10 ? (int)memory_size : 10;
    for (int i = 0; i < show; ++i) {
        if (i == 9 || i == memory_size - 1)
            printf(" %d", memory[i]);
        else
            printf(" %d,", memory[i]);
    }
    printf(" ]");
}
