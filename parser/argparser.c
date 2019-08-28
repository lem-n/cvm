#include "argparser.h"

cmd_args* args_parse(int argc, char** argv) {
    cmd_args* args = malloc(sizeof(cmd_args));
    if (!args) return NULL;

    size_t max_size = (argc - 1) * sizeof(arg_flag);
    args->flags = malloc(max_size);

    if (!args->flags) {
        free(args);
        return NULL;
    }

    int current = 1;
    int added = 0;

    while (argc > current) {
        if (argv[current][0] == '-') {
            args->flags[added].token = argv[current];

            if (argv[current + 1] != NULL && argv[current + 1][0] != '-') {
                args->flags[added].value = argv[current + 1];
                current += 2;
            }
            else {
                args->flags[added].value = "true";
                current++;
            }
            added++;
            continue;
        }
        current++;
    }

    if (added < argc - 1) {
        args->flags = realloc(args->flags, added * sizeof(arg_flag));
        if (!args->flags) {
            free(args);
            return NULL;
        }
    }

    args->count = added;
    return args;
}

char* args_get(cmd_args* args, const char* flag) {
    for (int i = 0; i < args->count; ++i) {
        if (strcmp(args->flags[i].token, flag) == 0)
            return args->flags[i].value;
    }
    return NULL;
}

void args_free(cmd_args* args) {
    if (!args || !args->flags) return;

    free(args->flags);
    free(args);
}
