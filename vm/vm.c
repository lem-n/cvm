#include "vm.h"

vm_container* vm_create(int code[], size_t code_length, int entry, size_t memory_size) {
    vm_container* vm = malloc(sizeof(vm_container));
    if (!vm) exit_error(NULL, "Could not allocate memory for VM struct.");

    // copy over the bytecode of the program
    vm->bytecode = malloc(code_length * sizeof(int));
    memcpy(vm->bytecode, code, code_length * sizeof(int));
    vm->bytecode_size = code_length;

    // create buffer for our program memory store
    vm->memory = calloc(memory_size, sizeof(int));
    if (!vm->memory) exit_error(vm, "Could not allocate VM data memory.");
    vm->memory_size = memory_size;

    // zero out stack
    memset(vm->stack, 0, sizeof(vm->stack));

    vm->flags = 0;          // initialize flags to 0
    vm->instr_ptr = entry;  // set program entry point
    vm->stack_ptr = -1;     // set stack pointer before top of stack

    return vm;
}

void vm_run(vm_container* vm) {
    while (vm->instr_ptr < vm->bytecode_size) {
        int opcode = vm->bytecode[vm->instr_ptr];

        if (vm_trace) {
            trace_op(opcode, vm->instr_ptr, vm->bytecode);
            printf("\n");
        }

        vm->instr_ptr++;

        switch (opcode) {
            case OPCODE_ICONST: instr_iconst(vm); break;
            case OPCODE_GLOAD:  instr_gload(vm); break;
            case OPCODE_GSTORE: instr_gstore(vm); break;
            case OPCODE_POP:    instr_pop(vm); break;
            case OPCODE_IADD:   instr_iadd(vm); break;
            case OPCODE_ISUB:   instr_isub(vm); break;
            case OPCODE_IMUL:   instr_imul(vm); break;
            case OPCODE_IDIV:   instr_idiv(vm); break;
            case OPCODE_JMP:    instr_jmp(vm); break;
            case OPCODE_JMPZ:   instr_jmpz(vm); break;
            case OPCODE_JMPNZ:  instr_jmpnz(vm); break;
            case OPCODE_PRINT:  instr_print(vm); break;
            case OPCODE_HALT:   return;
            default: exit_error(vm, "Encountered unknown bytecode instruction."); return;
        }

        if (vm_trace) {
            trace_stack(vm->stack, STACK_MAX_SIZE);
            printf("\n");
            trace_memory(vm->memory, vm->memory_size);
            printf("\nIP: %d | SP: %d\n\n", vm->instr_ptr, vm->stack_ptr);
        }
    }
}

void vm_destroy(vm_container* vm) {
    free(vm->bytecode);
    free(vm->memory);
    free(vm);
}
