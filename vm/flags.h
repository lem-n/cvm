#ifndef VM_FLAGS_H
#define VM_FLAGS_H

#include "vmdef.h"

extern const unsigned char FLAG_CARRY;
extern const unsigned char FLAG_ZERO;
extern const unsigned char FLAG_SIGN;
extern const unsigned char FLAG_OVERFLOW;

extern const unsigned char FLAG_EQUAL;
extern const unsigned char FLAG_GREATER;
extern const unsigned char FLAG_LESS;

/* Handle flag setting after arithmetic operation was done. */
void handle_arithmetic_flags(vm_container*, int);

#endif // VM_FLAGS_H
