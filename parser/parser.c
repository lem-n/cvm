#include "parser.h"

int parse_opcode(char* buffer) {
    for (int i = 0; i < BYTECODE_COUNT; ++i) {
        if (strcicmp(buffer, opcodes[i].opname) == 0) {
            return opcodes[i].opcode;
        }
    }
    return -1;
}

bytecode* read_bytecode(const char* filepath, int parser_type) {
    FILE* fp;
    char line[128];
    long file_len;

    bytecode* bc = malloc(sizeof(bytecode));

    bc->length = 12;
    bc->code = calloc(bc->length, sizeof(int));

    fp = fopen(filepath, "r");

    if (!fp) {
        perror("Could not open file.\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    file_len = ftell(fp);
    rewind(fp);

    char* pch;

    int i = 0;
    while (fgets(line, file_len, fp) != NULL) {
        pch = strtok(line, " ");

        while (pch != NULL) {
            size_t toklen = strlen(pch);

            if (pch[toklen - 1] == '\n') {
                pch[toklen - 1] = '\0';
            }

            if (bc->length <= i) {
                bc->length += 12;
                bc->code = realloc(bc->code, bc->length * sizeof(int));
                if (!bc->code) {
                    perror("Could not allocate space for bytecode.\n");
                    exit(1);
                }
            }

            // make copy of string and remove potential whitespace
            char* str = malloc(toklen + 1);
            strncpy(str, pch, toklen + 1);
            strwsrm(str);

            int value;

            if (*str) {
                value = parse_opcode(str);

                if (value == -1) {
                    if (parser_type == PARSE_TYPE_WORD) {
                        value = strtol(str, NULL, 10);
                    } else if (parser_type == PARSE_TYPE_HEX) {

                        value = strtol(str, NULL, 16);
                    } else {
                        fprintf(stderr, "Invalid parsing type provided.\n");
                        exit(1);
                    }
                }

                bc->code[i++] = value;
            }

            free(str);
            pch = strtok(NULL, " ");
        }
    }

    fclose(fp);

    if (bc->length > i) {
        bc->length = i;
        bc->code = realloc(bc->code, bc->length * sizeof(int));
    }

    return bc;
}
