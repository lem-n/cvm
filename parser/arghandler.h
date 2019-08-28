#ifndef PARSER_ARG_HANDLER_H
#define PARSER_ARG_HANDLER_H

#include "argparser.h"
#include "parser.h"

typedef struct _options {
    int opt_source_type;
    int opt_memsize;
    int opt_trace;
    int opt_output_hex;
} options;

options parse_arguments(int argc, char* argv[]);

#endif // PARSER_ARG_HANDLER_H
