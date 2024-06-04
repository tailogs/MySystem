#ifndef CONSOLE_COLOR_H
#define CONSOLE_COLOR_H

#include <iostream>
#include <windows.h>

// Класс для цветного вывода текста в консоль
class ConsoleColor {
public:
    enum Color {
        BLACK,
        BLUE,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        BROWN,
        LIGHT_GRAY,
        DARK_GRAY,
        LIGHT_BLUE,
        LIGHT_GREEN,
        LIGHT_CYAN,
        LIGHT_RED,
        LIGHT_MAGENTA,
        YELLOW,
        WHITE
    };

    static void SetTextColor(Color color);
    static void SetBackgroundColor(Color color);
    static void ResetColor();
    static void SetColors(Color textColor, Color backgroundColor);
};

#endif // CONSOLE_COLOR_H

