#include "flags.h"

const unsigned char FLAG_CARRY    = 1 << 0;
const unsigned char FLAG_ZERO     = 1 << 1;
const unsigned char FLAG_SIGN     = 1 << 2;
const unsigned char FLAG_OVERFLOW = 1 << 3;

const unsigned char FLAG_EQUAL    = 1 << 4;
const unsigned char FLAG_GREATER  = 1 << 5;
const unsigned char FLAG_LESS     = 1 << 6;

void handle_arithmetic_flags(vm_container* vm, int result) {
    // handle zero flag
    if (result == 0) vm->flags |= FLAG_ZERO;
    else vm->flags &= ~FLAG_ZERO;

    // handle sign/negative flag
    if (result < 0) vm->flags |= FLAG_SIGN;
    else vm->flags &= ~FLAG_SIGN;
}
