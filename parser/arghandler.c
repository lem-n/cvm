#include "arghandler.h"

#define PROGNAME "cvm"

void show_error(const char* const msg, const int errcode, const char help) {
    if (msg && msg[0]) {
        fprintf(stderr, "%s: %s", PROGNAME, msg);
        if (errcode > 0) {
            fprintf(stderr, ": %s.", strerror(errcode));
        }
        fprintf(stderr, "\n");
    }
    if (help) {
        fprintf(stderr, "Try '%s --help' for more information.\n", PROGNAME);
    }
}

void show_cmd_help() {
    printf("CVM usage: cvm <inputfile> [options]\n");
    printf("\nOptions:\n"
           "  -h, --help                   Display this help menu and exit\n"
           "  -t, --type <hex|word>        Set the content-type of the input file.\n"
           "  -m, --memory <data-slots>    Set the memory capacity for the interpreter.\n"
           "  -d, --debug                  Shows runtime trace information.\n"
           "\n");
}

const arg_opts args_parse(int argc, const char* const argv[]) {
    // define arg flags
    const struct ap_Option cmd_opts[] = {
        {'h', "help", ap_no},
        {'t', "type", ap_yes},
        {'m', "memory", ap_yes},
        {'d', "debug", ap_no},
    };

    // define opts struct and set default values
    arg_opts opts = {0, 512, 1};
    struct Arg_parser cmd_parser;

    if (!ap_init(&cmd_parser, argc, argv, cmd_opts, 0)) {
        show_error("Not enough memory!", 0, 0);
        exit(1);
    }

    if (ap_error(&cmd_parser)) {
        show_error(ap_error(&cmd_parser), 0, 1);
        exit(1);
    }

    for (int arg_index = 0; arg_index < ap_arguments(&cmd_parser); ++arg_index) {
        const int code = ap_code(&cmd_parser, arg_index);
        if (!code) {
            break;
        }

        const char* arg = ap_argument(&cmd_parser, arg_index);

        switch (code) {
            case 't': {
                opts.type = strcmp(arg, "hex") == 0 ? 0 : 1;
                break;
            }
            case 'm': {
                opts.data_size = strtol(arg, NULL, 10);
                break;
            }
            case 'd': {
                opts.show_trace = 1;
                break;
            }
            case 'h':
                show_cmd_help();
                exit(0);
            default:
                show_error("uncaught options.", 0, 0);
                break;
        }
    }

    return opts;
}
