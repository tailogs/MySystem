# virtual_machine.nim

const MEMORY_SIZE = 256

type
  VirtualMachine = object
    memory: array[0..MEMORY_SIZE - 1, char]

proc initializeMemory(vm: var VirtualMachine) =
  for i in 0..MEMORY_SIZE - 1:
    vm.memory[i] = '\0'

proc loadProgram(vm: var VirtualMachine, program: string) =
  for i, c in program:
    vm.memory[i] = c

proc executeProgram(vm: VirtualMachine) =
  for i in 0..MEMORY_SIZE - 1:
    if vm.memory[i] == '\0':
      break
    echo vm.memory[i]


var vm: VirtualMachine
let program = "Hello, World!\0"

initializeMemory(vm)
loadProgram(vm, program)
executeProgram(vm)
