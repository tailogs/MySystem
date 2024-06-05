## MySystem - Виртуальная машина и консольный интерфейс

![image](https://github.com/tailogs/MySystem/assets/69743960/39fc16a0-f93b-4bb1-b747-262d64a73645)

*Рисунок 1. Скриншот запущенной виртуальной машины*

**MySystem** - это простая виртуальная машина с консольным интерфейсом, позволяющая выполнять пользовательские программы, написанные на базовом наборе инструкций. Виртуальная машина также поддерживает работу со строками.

> Это README содержит обзор системы, инструкции по сборке и запуску, а также руководство по написанию программ для виртуальной машины.

### Сборка и запуск

Для сборки исполняемого файла MySystem используйте предоставленный Makefile:

```
make
```

Это скомпилирует исходный код и создаст исполняемый файл `MySystem.exe`.

Чтобы запустить исполняемый файл, используйте следующую команду:

```
make run
```

Либо вы можете собрать и запустить за один шаг:

```
make build_and_run
```

После запуска программы вы можете очистить сгенерированные файлы с помощью:

```
make clean
```

### Команды консоли

Консольный интерфейс предоставляет следующие команды:

- `help`: Показать список доступных команд.
- `run <filename>`: Запустить программу виртуальной машины из файла (инструкции ниже).
- `clear`: Очистить экран консоли.
- `exit`: Выйти из системы.

### Написание программ для виртуальной машины

Виртуальная машина поддерживает следующие инструкции:

- `PUSH <value>`: Поместить значение (число или строку в двойных кавычках) в стек.
- `POP`: Удалить верхнее значение из стека и вывести его как символ.
- `PRINT_STRING`: Вывести строку, хранящуюся в стеке.
- `PRINT`: Напечатать верхнее значение в стеке.
- `ADD`: Сложить два верхних значения в стеке и поместить результат.
- `SUB`: Вычесть два верхних значения в стеке и поместить результат.
- `MUL`: Перемножить два верхних значения в стеке и поместить результат.
- `DIV`: Разделить два верхних значения в стеке и поместить результат.

Чтобы запустить программу, введите команду `run <filename>` в консоли, где `<filename>` - имя файла, содержащего инструкции программы. Каждая инструкция должна быть записана на отдельной строке.

### Примеры программ 

#### Файл `hello_world.txt`:

```
PUSH "Hello, world!"
PRINT_STRING
```

Эта программа поместит строку `"Hello, world!"` в стек и выведет ее с помощью команды `PRINT_STRING`.

```sh
MySystem> run hello_world.txt
Hello, world!
```

#### Файл `operations.txt`:

```
PUSH 5
PUSH 10
ADD

PUSH 5
PUSH 10
SUB

PUSH 5
PUSH 10
MUL

PUSH 5
PUSH 10
DIV
```

Эта программа вычислит и выведет результаты всех арифметических операций.

```sh
MySystem> run operations.txt
Result of addition: (10 + 5) = 15
Result of subtraction: (10 - 5) = 5
Result of multiplication: (10 * 5) = 50
Result of division: (10 / 5) = 5
```

### Проблемы:

- **CTRL+C:** Не рекомендуется использовать эту комбинацию, так-как она ломает цвета консоли на текущей сессии, потом придеться перезагружать её. Лучше всего использовать специальную команду `exit`.
