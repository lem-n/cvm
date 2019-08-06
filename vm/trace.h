#ifndef VM_TRACE_H
#define VM_TRACE_H

#include <stdio.h>
#include "bytecode.h"

void trace_op(int, int, int[]);

void trace_stack(int[], size_t);

void trace_memory(int[], size_t);

#endif  // VM_TRACE_H
