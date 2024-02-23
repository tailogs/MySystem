#include <stdio.h>
#include "virtual_machine.h"

int main() {
    virtual_machine vm;
    char program[] = "Loading...\nWho you are?\n";

    initialize_memory(&vm);
    load_program(&vm, program);
    execute_program(&vm);

    return 0;
}