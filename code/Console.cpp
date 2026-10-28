#include "Console.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

void Console::activerCouleurs() {
#ifdef _WIN32
    HANDLE sortie = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (GetConsoleMode(sortie, &mode)) {
        SetConsoleMode(sortie, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
#endif
}

void Console::effacer() {
    std::cout << "\033[2J\033[H";
}

void Console::titre(const std::string& texte) {
    separation();
    std::cout << cyan << texte << reset << std::endl;
    separation();
}

void Console::separation() {
    std::cout << gris << "----------------------------------------" << reset << std::endl;
}
