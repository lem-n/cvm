#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _bytecode {
    int* code;
    size_t length;
} bytecode;

bytecode* read_bytecode(char*);

#endif // PARSER_PARSER_H