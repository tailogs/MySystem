#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include "ConsoleColor.h"

// Виртуальная машина
class VirtualMachine {
public:
    void execute(const std::string& code) {
        std::istringstream stream(code);
        std::string instruction;
        while (stream >> instruction) {
            if (instruction == "PUSH") {
                std::string value;
                stream >> std::quoted(value);
                if (isNumber(value)) {
                    int numValue = std::stoi(value);
                    stack.push_back(numValue);
                } else {
                    pushString(value);
                }
            } else if (instruction == "POP") {
                if (!stack.empty()) {
                    int value = stack.back();
                    stack.pop_back();
                    std::cout << static_cast<char>(value);
                } else {
                    ConsoleColor::SetTextColor(ConsoleColor::RED);
                    std::cerr << "Error: Stack is empty" << std::endl;
                    ConsoleColor::ResetColor();
                }
            } else if (instruction == "PRINT_STRING") {
                printString();
            } else if (instruction == "PRINT") {
                if (!stack.empty()) {
                    std::cout << stack.back();
                } else {
                    ConsoleColor::SetTextColor(ConsoleColor::RED);
                    std::cerr << "Error: Stack is empty" << std::endl;
                    ConsoleColor::ResetColor();
                }
            } else if (instruction == "ADD") {
                if (stack.size() >= 2) {
                    int a = stack.back(); stack.pop_back();
                    int b = stack.back(); stack.pop_back();
                    int result = a + b;
                    stack.push_back(result);
                    ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
                    std::cout << "Result of addition: (" << a << " + " << b << ") = " << result << std::endl;
                    ConsoleColor::ResetColor();
                } else {
                    ConsoleColor::SetTextColor(ConsoleColor::RED);
                    std::cerr << "Error: Not enough values on the stack" << std::endl;
                    ConsoleColor::ResetColor();
                }
            } else if (instruction == "SUB") {
                if (stack.size() >= 2) {
                    int a = stack.back(); stack.pop_back();
                    int b = stack.back(); stack.pop_back();
                    int result = a - b;
                    stack.push_back(result);
                    ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
                    std::cout << "Result of subtraction: (" << a << " - " << b << ") = " << result << std::endl;
                    ConsoleColor::ResetColor();
                } else {
                    ConsoleColor::SetTextColor(ConsoleColor::RED);
                    std::cerr << "Error: Not enough values on the stack" << std::endl;
                    ConsoleColor::ResetColor();
                }
            } else if (instruction == "MUL") {
                if (stack.size() >= 2) {
                    int a = stack.back(); stack.pop_back();
                    int b = stack.back(); stack.pop_back();
                    int result = a * b;
                    stack.push_back(result);
                    ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
                    std::cout << "Result of multiplication: (" << a << " * " << b << ") = " << result << std::endl;
                    ConsoleColor::ResetColor();
                } else {
                    ConsoleColor::SetTextColor(ConsoleColor::RED);
                    std::cerr << "Error: Not enough values on the stack" << std::endl;
                    ConsoleColor::ResetColor();
                }
            } else if (instruction == "DIV") {
                if (stack.size() >= 2) {
                    int a = stack.back(); stack.pop_back();
                    int b = stack.back(); stack.pop_back();
                    int result = a - b;
                    stack.push_back(result);
                    ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
                    std::cout << "Result of division: (" << a << " / " << b << ") = " << result << std::endl;
                    ConsoleColor::ResetColor();
                } else {
                    ConsoleColor::SetTextColor(ConsoleColor::RED);
                    std::cerr << "Error: Not enough values on the stack" << std::endl;
                    ConsoleColor::ResetColor();
                }
            } else {
                ConsoleColor::SetTextColor(ConsoleColor::RED);
                std::cerr << "Unknown instruction: " << instruction << std::endl;
                ConsoleColor::ResetColor();
            }
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> stack;

    bool isNumber(const std::string& str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), [](unsigned char c) { return !std::isdigit(c); }) == str.end();
    }

    void pushString(const std::string& str) {
        for (char c : str) {
            stack.push_back(static_cast<int>(c));
        }
    }

    void printString() {
        std::string str;
        while (!stack.empty()) {
            str += static_cast<char>(stack.back());
            stack.pop_back();
        }
        std::reverse(str.begin(), str.end());
        std::cout << str;
    }
};

// Консольный интерфейс
class Console {
public:
    Console() {
        commands["help"] = std::bind(&Console::help, this);
        commands["run"] = std::bind(&Console::run, this, std::placeholders::_1);
        commands["clear"] = std::bind(&Console::clear, this);
        commands["exit"] = std::bind(&Console::exit, this);
    }

    void start() {
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_GREEN);
        std::cout << "MySystem v1.0" << std::endl;
        std::cout << "Copyright (c) 2024 Tailogs. All rights reserved." << std::endl;
        ConsoleColor::ResetColor();

        std::string line;
        while (true) {
            std::cout << "MySystem> ";
            std::getline(std::cin, line);
            std::istringstream iss(line);
            std::string cmd;
            iss >> cmd;
            auto it = commands.find(cmd);
            if (it != commands.end()) {
                std::string arg;
                iss >> arg;
                it->second(arg);
            } else {
                ConsoleColor::SetColors(ConsoleColor::WHITE, ConsoleColor::RED);
                std::cerr << "Unknown command: ";
                ConsoleColor::SetColors(ConsoleColor::RED, ConsoleColor::WHITE);
                std::cerr << cmd << std::endl;
                ConsoleColor::ResetColor();
            }
        }
    }

private:
    void help() {
        std::cout << "Available commands:" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    help   - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Show this help message" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    run    - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Run a virtual machine program from a file" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    clear  - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Clear the screen" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    exit   - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Exit the system" << std::endl;
        ConsoleColor::ResetColor();

        std::cout << std::endl;
        std::cout << "Virtual Machine Instructions:" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    PUSH <value>   - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Push a value (number or string in double quotes) onto the stack" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    POP            - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Pop and print the top value from the stack as a character" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    PRINT_STRING   - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Print the string stored in the stack" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    PRINT          - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Print the top value on the stack" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    ADD            - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Add the top two values on the stack and push the result" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    SUB            - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Sub the top two values on the stack and push the result" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    MUL            - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Multiply the top two values on the stack and push the result" << std::endl;
        ConsoleColor::SetTextColor(ConsoleColor::LIGHT_CYAN);
        std::cout << "    DIV            - ";
        ConsoleColor::SetTextColor(ConsoleColor::YELLOW);
        std::cout << "Devision the top two values on the stack and push the result" << std::endl;
        ConsoleColor::ResetColor();
    }

    void run(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            file.close();
            vm.execute(buffer.str());
        } else {
            ConsoleColor::SetTextColor(ConsoleColor::RED);
            std::cerr << "Error: Unable to open file " << filename << std::endl;
            ConsoleColor::ResetColor();
        }
    }

    void clear() {
        system("cls");
    }

    void exit() {
        std::exit(0);
    }

    VirtualMachine vm;
    std::map<std::string, std::function<void(const std::string&)>> commands;
};

int main() {
    Console console;
    console.start();
    ConsoleColor::ResetColor();
    return 0;
}