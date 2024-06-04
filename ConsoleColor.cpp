#include "ConsoleColor.h"

void ConsoleColor::SetTextColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>((consoleInfo.wAttributes & 0xF0) | color));
}

void ConsoleColor::SetBackgroundColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>((consoleInfo.wAttributes & 0x0F) | (color << 4)));
}

void ConsoleColor::ResetColor() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void ConsoleColor::SetColors(Color textColor, Color backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<WORD>((backgroundColor << 4) | textColor));
}