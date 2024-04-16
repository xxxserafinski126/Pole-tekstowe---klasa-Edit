#include "color_manip.h"

std::ostream& setColorAttribute(std::ostream& os, WORD attribute) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, attribute);
    return os;
}

std::ostream& operator<<(std::ostream& os, const ColorAttribute& ca) {
    return setColorAttribute(os, ca.attr);
}

std::ostream& black(std::ostream& os) { return setColorAttribute(os, 0); }
std::ostream& blue(std::ostream& os) { return setColorAttribute(os, 1); }
std::ostream& green(std::ostream& os) { return setColorAttribute(os, 2); }
std::ostream& cyan(std::ostream& os) { return setColorAttribute(os, 3); }
std::ostream& red(std::ostream& os) { return setColorAttribute(os, 4); }
std::ostream& magenta(std::ostream& os) { return setColorAttribute(os, 5); }
std::ostream& yellow(std::ostream& os) { return setColorAttribute(os, 14); }
std::ostream& white(std::ostream& os) { return setColorAttribute(os, 15); }
std::ostream& light_blue(std::ostream& os) { return setColorAttribute(os, 9); }
std::ostream& light_green(std::ostream& os) { return setColorAttribute(os, 10); }
std::ostream& light_cyan(std::ostream& os) { return setColorAttribute(os, 11); }
std::ostream& light_red(std::ostream& os) { return setColorAttribute(os, 12); }
std::ostream& light_magenta(std::ostream& os) { return setColorAttribute(os, 13); }
std::ostream& light_yellow(std::ostream& os) { return setColorAttribute(os, 14); }
std::ostream& light_white(std::ostream& os) { return setColorAttribute(os, 15); }
std::ostream& gray(std::ostream& os) { return setColorAttribute(os, 8); }

ColorAttribute setColor(WORD attributes) {
    return ColorAttribute(attributes);
}

std::ostream& defcolor(std::ostream& os) { return setColorAttribute(os, 7); }