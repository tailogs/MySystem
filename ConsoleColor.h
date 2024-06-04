#ifndef CONSOLE_COLOR_H
#define CONSOLE_COLOR_H

#include <iostream>
#include <string>
#include <windows.h>

// Класс для цветного вывода текста в консоль
class ConsoleColor {
public:
    enum Color {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHT_GRAY = 7,
        DARK_GRAY = 8,
        LIGHT_BLUE = 9,
        LIGHT_GREEN = 10,
        LIGHT_CYAN = 11,
        LIGHT_RED = 12,
        LIGHT_MAGENTA = 13,
        YELLOW = 14,
        WHITE = 15
    };

    static void SetTextColor(Color color);
    static void SetBackgroundColor(Color color);
    static void ResetColor();
    static void SetColors(Color textColor, Color backgroundColor);
};

#endif // CONSOLE_COLOR_H