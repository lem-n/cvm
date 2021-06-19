#ifndef VM_INSTR_H
#define VM_INSTR_H

#include "flags.h"
#include "safety.h"
#include "vmdef.h"

/* Push integer to top of stack. */
void instr_iconst(vm_container*);

/* Loads a value onto stack from data on address x. */
void instr_gload(vm_container*);

/* Store value from stack into data on address x. */
void instr_gstore(vm_container*);

/* Prints value from top of stack to stdout. */
void instr_iprint(vm_container*);

void instr_cprint(vm_container*);

/* Pops top two stack values and pushes their sum to the stack. */
void instr_iadd(vm_container*);

/* Pops top two stack values and pushes their difference to the stack. */
void instr_isub(vm_container*);

/* Pops top two stack values and pushes their product to the stack. */
void instr_imul(vm_container*);

/* Pop top two stack values and pushes their quotient to the stack. */
void instr_idiv(vm_container*);

void instr_inc(vm_container*);

void instr_dec(vm_container*);

void instr_cmp(vm_container*);

/* Pops the top of the stack. */
void instr_pop(vm_container*);

/* Jump to code address. */
void instr_jmp(vm_container*);

void instr_jmpz(vm_container*);

void instr_jmpnz(vm_container*);

void instr_jmplt(vm_container*);

void instr_jmpgt(vm_container*);

/* Get a single character from stdin and push it to the top of the stack. */
void instr_getc(vm_container*);

#endif // VM_INSTR_H
