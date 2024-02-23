run:
	gcc src\my_system.c src\virtual_machine.c -o bin\my_system.exe 
	bin\my_system.exe

build:
	gcc src\my_system.c src\virtual_machine.c -o bin\my_system.exe 

clear:
	del bin\my_system.exe