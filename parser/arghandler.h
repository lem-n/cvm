#ifndef PARSER_ARGHANDLER_H
#define PARSER_ARGHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carg_parser.h"
#include "parser.h"

typedef struct _arg_opts {
    int show_trace;
    int data_size;
    enum parse_type type;
} arg_opts;

const arg_opts args_parse(int argc, const char* const argv[]);

#endif // PARSER_ARGHANDLER_H
