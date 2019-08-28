#ifndef VM_VMDEF_H
#define VM_VMDEF_H

#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#define STACK_MAX_SIZE 128

typedef struct _vm_container {
    unsigned char flags;

    int* memory;
    size_t memory_size;

    int* bytecode;
    size_t bytecode_size;

    int stack[STACK_MAX_SIZE];

    int stack_ptr;
    int instr_ptr;
    int frame_ptr;
} vm_container;

#endif // VMVM_DEF_H