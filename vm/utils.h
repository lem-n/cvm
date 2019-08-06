#ifndef VM_UTILS_H
#define VM_UTILS_H

#include <stdio.h>
#include "vm_def.h"

static void exit_error(vm_container* vm, const char* err_msg) {
    int ip;

    if (!vm) ip = 0;
    ip = vm->instr_ptr;

    fprintf(stderr, "VM was terminated.\nError: %s (instruction pointer = %d)\n", err_msg, ip);
    
    free(vm->bytecode);
    free(vm->memory);
    free(vm);

    exit(EXIT_FAILURE);
}

#endif // VM_UTILS_H