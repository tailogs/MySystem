// main.c
#include <stdio.h>
#include "virtual_machine.h"

int main() {
    VirtualMachine vm;
    char program[] = "Loading...\nWho you are?\n";

    initializeMemory(&vm);
    loadProgram(&vm, program);
    executeProgram(&vm);

    return 0;
}