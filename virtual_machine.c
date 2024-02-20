// virtual_machine.c
#include <stdio.h>

#define MEMORY_SIZE 256

typedef struct {
    char memory[MEMORY_SIZE];
} VirtualMachine;

void initializeMemory(VirtualMachine* vm) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        vm->memory[i] = '\0';
    }
}

void loadProgram(VirtualMachine* vm, char* program) {
    int i = 0;
    while (program[i] != '\0') {
        vm->memory[i] = program[i];
        i++;
    }
}

void executeProgram(VirtualMachine* vm) {
    int i = 0;
    while (vm->memory[i] != '\0') {
        printf("%c", vm->memory[i]);
        i++;
    }
}