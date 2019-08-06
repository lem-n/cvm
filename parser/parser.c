#include "parser.h"

bytecode* read_bytecode(char* filepath) {
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
            if (pch[toklen - 1] == '\n') pch[toklen - 1] = '\0';

            if (bc->length <= i) {
                bc->length += 12;
                bc->code = realloc(bc->code, bc->length * sizeof(int));
                if (!bc->code) {
                    perror("Could not allocate space for bytecode.\n");
                    exit(1);
                }
            }

            int value = strtol(pch, NULL, 16);
            bc->code[i++] = value;
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