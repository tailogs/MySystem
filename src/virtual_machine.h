// virtual_machine.h
#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H
#define MEMORY_SIZE 256

typedef struct {
    char memory[MEMORY_SIZE];
} virtual_machine;

void initialize_memory(virtual_machine* vm);
void load_program(virtual_machine* vm, char* program);
void execute_program(virtual_machine* vm);

#endif