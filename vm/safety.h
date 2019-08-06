#ifndef VM_SAFETY_H
#define VM_SAFETY_H

#include <stdlib.h>
#include "utils.h"

static inline void safe_stack_ptr_overflow(vm_container* vm, int offset) {
    if (vm->stack_ptr + offset > STACK_MAX_SIZE)
        exit_error(vm, "Stack pointer overflow.");
}

static inline void safe_stack_ptr_underflow(vm_container* vm, int offset) {
    if (vm->stack_ptr - offset < -1)
        exit_error(vm, "Stack pointer underflow.");
}

static inline void safe_check_instr_ptr(vm_container* vm) {
    if (vm->instr_ptr > vm->bytecode_size)
        exit_error(vm, "Out of program bounds.");
    else if (vm->instr_ptr < 0)
        exit_error(vm, "Invalid program entry.");
}

#endif // VM_SAFETY_H