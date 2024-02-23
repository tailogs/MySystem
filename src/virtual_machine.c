// virtual_machine.c
#include <stdio.h>

#define MEMORY_SIZE 256

typedef struct {
    char memory[MEMORY_SIZE];
} virtual_machine;

void initialize_memory(virtual_machine* vm) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        vm->memory[i] = '\0';
    }
}

void load_program(virtual_machine* vm, char* program) {
    int i = 0;
    while (program[i] != '\0') {
        vm->memory[i] = program[i];
        i++;
    }
}

void execute_program(virtual_machine* vm) {
    int i = 0;
    while (vm->memory[i] != '\0') {
        printf("%c", vm->memory[i]);
        i++;
    }
}