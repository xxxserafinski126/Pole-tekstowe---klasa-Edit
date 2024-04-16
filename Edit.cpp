#include "edit.h"
#include <iostream>

Edit::Edit() : x(0), y(0), length(10), textColor(White), backgroundColor(Black) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
}

Edit::Edit(const Edit& other) : x(other.x), y(other.y), length(other.length),
textColor(other.textColor), backgroundColor(other.backgroundColor), text(other.text) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
}

Edit::~Edit() {
}

void Edit::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Edit::setLength(unsigned int len) {
    length = len;
}

void Edit::setText(const std::string& text) {
    this->text = text.substr(0, length);
}

void Edit::setTextColor(Color color) {
    textColor = color;
}

void Edit::setBackgroundColor(Color color) {
    backgroundColor = color;
}

std::string Edit::getText() const {
    return text;
}

void Edit::applyColors() {
    SetConsoleTextAttribute(hConsole, textColor + (backgroundColor << 4));
}

void Edit::clear() {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    DWORD written;
    FillConsoleOutputCharacter(hConsole, ' ', length, coord, &written);
    FillConsoleOutputAttribute(hConsole, consoleInfo.wAttributes, length, coord, &written);
}

void Edit::userText() {
    applyColors();
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, coord);
    char ch;
    while ((ch = _getch()) != 13) { 
        if (ch == '\b') { 
            if (!text.empty()) {
                text.pop_back();
                std::cout << "\b \b";
            }
        }
        else {
            if (text.length() < length) {
                text += ch;
                std::cout << ch;
            }
        }
    }
    clear();
}