#ifndef VM_TRACE_H
#define VM_TRACE_H

#include <stdio.h>
#include "bytecode.h"
#include "vmdef.h"

void trace_op(vm_container*, int);

void trace_stack(vm_container*);

void trace_memory(vm_container*);

#endif  // VM_TRACE_H
