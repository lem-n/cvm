#include "instr.h"

void instr_iconst(vm_container* vm) {
    safe_check_instr_ptr(vm);
    int value = vm->bytecode[vm->instr_ptr++];  // get value from code and step forward
    safe_stack_ptr_overflow(vm, 0);
    vm->stack[++vm->stack_ptr] = value;         // increase stack pointer so we're on the top, and then set the value
}

void instr_gload(vm_container* vm) {
    safe_check_instr_ptr(vm);
    int addr = vm->bytecode[vm->instr_ptr++];  // get address from bytecode
    int value = vm->memory[addr];
    safe_stack_ptr_overflow(vm, 0);
    vm->stack[++vm->stack_ptr] = value;  // put value on the stack
}

void instr_gstore(vm_container* vm) {
    safe_stack_ptr_overflow(vm, 0);
    int value = vm->stack[vm->stack_ptr];  // get value
    instr_pop(vm);
    safe_check_instr_ptr(vm);
    int addr = vm->bytecode[vm->instr_ptr++];  // get address
    vm->memory[addr] = value;                  // store value at address
}

void instr_print(vm_container* vm) {
    safe_stack_ptr_overflow(vm, 0);
    int value = vm->stack[vm->stack_ptr];  // get stack value
    instr_pop(vm);
    printf("%d\n", value);  // print value
}

void instr_iadd(vm_container* vm) {
    safe_stack_ptr_overflow(vm, 2);
    int operand1 = vm->stack[vm->stack_ptr];
    instr_pop(vm);
    int operand2 = vm->stack[vm->stack_ptr];
    instr_pop(vm);

    int sum = operand1 + operand2;
    handle_arithmetic_flags(vm, sum);
    vm->stack[++vm->stack_ptr] = sum;  // store sum onto stack
}

void instr_isub(vm_container* vm) {
    safe_stack_ptr_overflow(vm, 2);
    int operand1 = vm->stack[vm->stack_ptr];
    instr_pop(vm);
    int operand2 = vm->stack[vm->stack_ptr];
    instr_pop(vm);

    int diff = operand1 - operand2;
    handle_arithmetic_flags(vm, diff);
    vm->stack[++vm->stack_ptr] = diff;
}

void instr_imul(vm_container* vm) {
    safe_stack_ptr_overflow(vm, 2);
    int operand1 = vm->stack[vm->stack_ptr];
    instr_pop(vm);
    int operand2 = vm->stack[vm->stack_ptr];
    instr_pop(vm);

    int prod = operand1 * operand2;
    handle_arithmetic_flags(vm, prod);
    vm->stack[++vm->stack_ptr] = prod;
}

void instr_idiv(vm_container* vm) {
    safe_stack_ptr_overflow(vm, 2);
    int operand1 = vm->stack[vm->stack_ptr];
    instr_pop(vm);
    int operand2 = vm->stack[vm->stack_ptr];
    instr_pop(vm);

    int quot = operand1 / operand2;
    handle_arithmetic_flags(vm, quot);
    vm->stack[++vm->stack_ptr] = quot;
}

void instr_pop(vm_container* vm) {
    safe_stack_ptr_underflow(vm, 0);
    vm->stack[vm->stack_ptr--] = 0;
}

void instr_jmp(vm_container* vm) {
    safe_check_instr_ptr(vm);
    int addr = vm->bytecode[vm->instr_ptr];
    vm->instr_ptr = addr;
}

void instr_jmpz(vm_container* vm) {
    safe_check_instr_ptr(vm);
    int addr = vm->bytecode[vm->instr_ptr++];
    instr_pop(vm);

    // check if zero flag is set
    if (vm->flags & FLAG_ZERO)
        vm->instr_ptr = addr;
}

void instr_jmpnz(vm_container* vm) {
    safe_check_instr_ptr(vm);
    int addr = vm->bytecode[vm->instr_ptr++];
    instr_pop(vm);

    // check if zero flag is NOT set
    if (!(vm->flags & FLAG_ZERO))
        vm->instr_ptr = addr;
}