#include "../parser/arghandler.h"
#include "../parser/parser.h"
#include "vm.h"

int main(int argc, const char* const argv[]) {
    if (argc < 2) {
        printf("invalid usage: <filepath> [...flags]\n");
        return 1;
    }

    const arg_opts opts = args_parse(argc, argv);

    bytecode* bc = read_bytecode(argv[1], opts.type);

    if (!bc->code || bc->length == 0) {
        printf("err: invalid bytecode array.\n");
        return 1;
    }

    int entry = 0;
    vm_container* vm = vm_create(bc->code, bc->length, entry, opts.data_size);

    vm->trace = opts.show_trace;
    vm_run(vm);

    vm_destroy(vm);
    free(bc->code);
    free(bc);

    return 0;
}
