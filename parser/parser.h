#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "putils.h"
#include "../vm/bytecode.h"

enum parse_type {
    PARSE_TYPE_HEX,
    PARSE_TYPE_WORD
};

typedef struct _bytecode {
    int* code;
    size_t length;
} bytecode;

int parse_opcode(char*);

bytecode* read_bytecode(char*, int);

#endif // PARSER_PARSER_H