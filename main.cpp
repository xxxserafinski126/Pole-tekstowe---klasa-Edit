#include <iostream>
#include <conio.h>
#include "color_manip.h"

int main() {
    system("cls");
    std::cout << "Druga czesc programu" << std::endl;
    std::cout << yellow << "A" << red << "l" << blue << "a" << green << " m" << gray << "a"
        << light_blue << " k" << light_yellow << "o" << cyan << "t" << magenta << "a";
    std::cout << setColor(FOREGROUND_RED | BACKGROUND_GREEN) << "Miauu" << defcolor << " xxzyw";
    _getch();

    return 0;
}
