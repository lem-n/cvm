#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include "../vm/bytecode.h"
#include "putils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum parse_type { PARSE_TYPE_HEX, PARSE_TYPE_WORD };

typedef struct _bytecode {
    int* code;
    size_t length;
} bytecode;

int parse_opcode(char*);

bytecode* read_bytecode(const char*, int);

#endif // PARSER_PARSER_H
