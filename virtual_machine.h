// virtual_machine.h
#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H
#define MEMORY_SIZE 256

typedef struct {
    char memory[MEMORY_SIZE];
} VirtualMachine;

void initializeMemory(VirtualMachine* vm);
void loadProgram(VirtualMachine* vm, char* program);
void executeProgram(VirtualMachine* vm);

#endif