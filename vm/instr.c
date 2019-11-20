#include "instr.h"

void instr_iconst(vm_container* vm) {
    int value = vm->bytecode[vm->instr_ptr++];  // get value from code and step forward
    vm->stack[++vm->stack_ptr] = value;         // increase stack pointer so we're on the top, and then set the value
}

void instr_gload(vm_container* vm) {
    int addr = vm->bytecode[vm->instr_ptr++];  // get address from bytecode
    int value = vm->memory[addr];
    vm->stack[++vm->stack_ptr] = value;  // put value on the stack
}

void instr_gstore(vm_container* vm) {
    int value = vm->stack[vm->stack_ptr];  // get value
    instr_pop(vm);
    int addr = vm->bytecode[vm->instr_ptr++];  // get address
    vm->memory[addr] = value;                  // store value at address
}

void instr_iprint(vm_container* vm) {
    int value = vm->stack[vm->stack_ptr];  // get stack value
    instr_pop(vm);
    printf("%d\n", value);  // print value
}

void instr_cprint(vm_container* vm) {
    int value = vm->stack[vm->stack_ptr];  // get stack value
    instr_pop(vm);
    putc(value, stdout);
}

void instr_iadd(vm_container* vm) {
    int operand1 = vm->stack[vm->stack_ptr];
    instr_pop(vm);
    int operand2 = vm->stack[vm->stack_ptr];
    instr_pop(vm);

    int sum = operand1 + operand2;
    handle_arithmetic_flags(vm, sum);
    vm->stack[++vm->stack_ptr] = sum;  // store sum onto stack
}

void instr_isub(vm_container* vm) {
    int operand1 = vm->stack[vm->stack_ptr];
    instr_pop(vm);
    int operand2 = vm->stack[vm->stack_ptr];
    instr_pop(vm);

    int diff = operand1 - operand2;
    handle_arithmetic_flags(vm, diff);
    vm->stack[++vm->stack_ptr] = diff;
}

void instr_imul(vm_container* vm) {
    int operand1 = vm->stack[vm->stack_ptr];
    instr_pop(vm);
    int operand2 = vm->stack[vm->stack_ptr];
    instr_pop(vm);

    int prod = operand1 * operand2;
    handle_arithmetic_flags(vm, prod);
    vm->stack[++vm->stack_ptr] = prod;
}

void instr_idiv(vm_container* vm) {
    int operand1 = vm->stack[vm->stack_ptr];
    instr_pop(vm);
    int operand2 = vm->stack[vm->stack_ptr];
    instr_pop(vm);

    int quot = operand1 / operand2;
    handle_arithmetic_flags(vm, quot);
    vm->stack[++vm->stack_ptr] = quot;
}

void instr_inc(vm_container* vm) {
    int value = vm->stack[vm->stack_ptr] + 1;
    handle_arithmetic_flags(vm, value);
    vm->stack[vm->stack_ptr] = value;
}

void instr_dec(vm_container* vm) {
    int value = vm->stack[vm->stack_ptr] - 1;
    handle_arithmetic_flags(vm, value);
    vm->stack[vm->stack_ptr] = value;
}

void instr_cmp(vm_container* vm) {
    int operand1 = vm->stack[vm->stack_ptr];
    instr_pop(vm);
    int operand2 = vm->stack[vm->stack_ptr];
    instr_pop(vm);

    if (operand1 == operand2) {
        vm->flags &= ~FLAG_LESS;
        vm->flags &= ~FLAG_GREATER;
        vm->flags |= FLAG_EQUAL;
    }
    else if (operand1 > operand2) {
        vm->flags &= ~FLAG_LESS;
        vm->flags &= ~FLAG_EQUAL;
        vm->flags |= FLAG_GREATER;
    }
    else if (operand1 < operand2) {
        vm->flags &= ~FLAG_GREATER;
        vm->flags &= ~FLAG_EQUAL;
        vm->flags |= FLAG_LESS;
    }
}

void instr_pop(vm_container* vm) {
    vm->stack[vm->stack_ptr--] = 0;
    safe_check_stack_ptr(vm);
}

void instr_jmp(vm_container* vm) {
    int addr = vm->bytecode[vm->instr_ptr];
    vm->instr_ptr = addr;
}

void instr_jmpz(vm_container* vm) {
    int addr = vm->bytecode[vm->instr_ptr++];
    instr_pop(vm);

    // check if zero flag is set
    if (vm->flags & FLAG_ZERO)
        vm->instr_ptr = addr;
}

void instr_jmpnz(vm_container* vm) {
    int addr = vm->bytecode[vm->instr_ptr++];
    instr_pop(vm);

    // check if zero flag is NOT set
    if (!(vm->flags & FLAG_ZERO))
        vm->instr_ptr = addr;
}

void instr_jmplt(vm_container* vm) {
    int addr = vm->bytecode[vm->instr_ptr++];

    if (vm->flags & FLAG_GREATER)
        vm->instr_ptr = addr;
}

void instr_jmpgt(vm_container* vm) {
    int addr = vm->bytecode[vm->instr_ptr++];

    if (vm->flags & FLAG_LESS)
        vm->instr_ptr = addr;
}

void instr_getc(vm_container* vm) {
    vm->stack[vm->stack_ptr++] = fgetc(stdin);
}