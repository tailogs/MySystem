#include "ConsoleColor.h"

void ConsoleColor::SetTextColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>((consoleInfo.wAttributes & 0xF0) | static_cast<WORD>(color)));
}

void ConsoleColor::SetBackgroundColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>((consoleInfo.wAttributes & 0x0F) | (static_cast<WORD>(color) << 4)));
}

void ConsoleColor::SetColors(Color textColor, Color backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>((static_cast<WORD>(backgroundColor) << 4) | static_cast<WORD>(textColor)));
}

void ConsoleColor::ResetColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>((static_cast<WORD>(BLACK) << 4) | static_cast<WORD>(WHITE)));
}