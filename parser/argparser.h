#ifndef PARSER_ARG_PARSER
#define PARSER_ARG_PARSER

#include <malloc.h>
#include <string.h>

typedef struct _arg_flag {
    char* token;
    char* value;

} arg_flag;

typedef struct _cmd_args {
    arg_flag* flags;
    int count;
} cmd_args;

cmd_args* args_parse(int, char**);

char* args_get(cmd_args*, const char*);

void args_free(cmd_args*);

#endif // PARSER_ARG_PARSER