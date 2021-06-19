#include "vm.h"

vm_container* vm_create(int code[], size_t code_length, int entry, size_t memory_size) {
    vm_container* vm = malloc(sizeof(vm_container));

    if (!vm) {
        exit_error(NULL, "Could not allocate memory for VM struct.");
    }

    // copy over the bytecode of the program
    vm->bytecode = malloc(code_length * sizeof(int));
    memcpy(vm->bytecode, code, code_length * sizeof(int));
    vm->bytecode_size = code_length;

    // create buffer for our program memory store
    vm->memory = calloc(memory_size, sizeof(int));

    if (!vm->memory) {
        exit_error(vm, "Could not allocate VM data memory.");
    }

    vm->memory_size = memory_size;

    // zero out stack
    memset(vm->stack, 0, sizeof(vm->stack));

    vm->flags = 0;         // initialize flags to 0
    vm->instr_ptr = entry; // set program entry point
    vm->stack_ptr = -1;    // set stack pointer before top of stack

    return vm;
}

void vm_run(vm_container* vm) {
    while (vm->instr_ptr < vm->bytecode_size) {
        int opcode = vm->bytecode[vm->instr_ptr];

        vm->instr_ptr++;

        safe_check_instr_ptr(vm);
        safe_check_stack_ptr(vm);

        switch (opcode) {
            case OP_HALT:
                return;
            case OP_NOOP:
                break;
            case OP_ICONST:
                instr_iconst(vm);
                break;
            case OP_GLOAD:
                instr_gload(vm);
                break;
            case OP_GSTORE:
                instr_gstore(vm);
                break;
            case OP_POP:
                instr_pop(vm);
                break;
            case OP_IADD:
                instr_iadd(vm);
                break;
            case OP_ISUB:
                instr_isub(vm);
                break;
            case OP_IMUL:
                instr_imul(vm);
                break;
            case OP_IDIV:
                instr_idiv(vm);
                break;
            case OP_INC:
                instr_inc(vm);
                break;
            case OP_DEC:
                instr_dec(vm);
                break;
            case OP_CMP:
                instr_cmp(vm);
                break;
            case OP_JMP:
                instr_jmp(vm);
                break;
            case OP_JMPZ:
                instr_jmpz(vm);
                break;
            case OP_JMPNZ:
                instr_jmpnz(vm);
                break;
            case OP_IPRINT:
                instr_iprint(vm);
                break;
            case OP_CPRINT:
                instr_cprint(vm);
                break;
            case OP_GETC:
                instr_getc(vm);
                break;
            default:
                exit_error(vm, "Encountered unknown bytecode instruction.");
                return;
        }

        if (vm->trace) {
            trace_op(vm, opcode);
            trace_stack(vm);
            printf("\n");
            trace_memory(vm);
            printf("\n\n");
        }
    }
}

void vm_destroy(vm_container* vm) {
    free(vm->bytecode);
    free(vm->memory);
    free(vm);
}
