#ifndef VM_SAFETY_H
#define VM_SAFETY_H

#include <stdlib.h>
#include "utils.h"

static inline void safe_check_instr_ptr(vm_container* vm) {
    if (vm->instr_ptr > vm->bytecode_size)
        exit_error(vm, "Program out of bounds.");
    else if (vm->instr_ptr < 0)
        exit_error(vm, "Invalid program entry.");
}

static inline void safe_check_stack_ptr(vm_container* vm) {
    if (vm->stack_ptr < -1 || vm->stack_ptr > STACK_MAX_SIZE)
        exit_error(vm, "Stack pointer out of bounds.");
}

#endif // VM_SAFETY_H