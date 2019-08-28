#include "vm.h"
#include "../parser/parser.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("invalid usage: <filepath> [...flags]\n");
        return 1;
    }

    int parser_type = PARSE_TYPE_WORD;
    size_t memsize = 512;

    bytecode* bc = read_bytecode(argv[1], parser_type);

    if (!bc->code || bc->length == 0) {
        printf("err: invalid bytecode array.\n");
        return 1;
    }

    int entry = 0;
    vm_container* vm = vm_create(bc->code, bc->length, entry, memsize);

    vm_trace = FALSE;

    vm_run(vm);

    vm_destroy(vm);

    free(bc->code);
    free(bc);

    return 0;
}
