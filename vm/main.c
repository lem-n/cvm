#include "../parser/parser.h"
#include "vm.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("invalid usage: <filepath> <data_cap>\n");
        return 1;
    }

    bytecode* bc = read_bytecode(argv[1]);

    if (!bc->code || bc->length == 0) {
        printf("err: invalid bytecode array.\n");
        return 1;
    }

    int entry = 0;
    size_t data_cap = atoi(argv[2]);

    vm_container* vm = vm_create(bc->code, bc->length, entry, data_cap);

    vm_trace = FALSE;
    vm_run(vm);

    vm_destroy(vm);

    free(bc->code);
    free(bc);

    return 0;
}
