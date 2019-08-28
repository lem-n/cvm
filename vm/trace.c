#include "trace.h"

void trace_op(vm_container* vm, int op) {
    bytecode_instr instr = opcodes[op];

    printf("%04d: %s", vm->instr_ptr, instr.opname);
    if (instr.argc > 0) {
        for (int i = 1; i <= instr.argc; ++i) {
            if (i == instr.argc)
                printf(" %d", vm->bytecode[vm->instr_ptr + i]);
            else
                printf(" %d,", vm->bytecode[vm->instr_ptr + i]);
        }
    }
    printf("\n");
}

void trace_stack(vm_container* vm) {
    printf("STACK [");

    int show = STACK_MAX_SIZE < 10 ? (int)STACK_MAX_SIZE : 10;
    for (int i = 0; i < show; ++i) {
        if (i == 9)
            printf(" %d", vm->stack[i]);
        else
            printf(" %d,", vm->stack[i]);
    }
    printf(" ]");
}

void trace_memory(vm_container* vm) {
    printf("MEM:  [");

    int show = vm->memory_size < 10 ? (int)vm->memory_size : 10;
    for (int i = 0; i < show; ++i) {
        if (i == 9 || i == vm->memory_size - 1)
            printf(" %d", vm->memory[i]);
        else
            printf(" %d,", vm->memory[i]);
    }
    printf(" ]");
}
