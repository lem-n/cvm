#ifndef VM_VM_H
#define VM_VM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bytecode.h"
#include "instr.h"
#include "trace.h"
#include "utils.h"
#include "vmdef.h"

/* Create a new VM. */
vm_container* vm_create(int[], size_t, int, size_t);

/* Start the VM. */
void vm_run(vm_container*);

/* Free up memory used by VM. */
void vm_destroy(vm_container*);

#endif // VM_VM_H
