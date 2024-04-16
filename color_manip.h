#ifndef COLOR_MANIP_H
#define COLOR_MANIP_H

#include <iostream>
#include <windows.h>

// Klasa do przechowywania atrybutów koloru
class ColorAttribute {
public:
    explicit ColorAttribute(WORD attribute) : attr(attribute) {}
    friend std::ostream& operator<<(std::ostream& os, const ColorAttribute& ca);
private:
    WORD attr;
};

// Deklaracje funkcji manipulatorów kolorów
std::ostream& black(std::ostream& os);
std::ostream& blue(std::ostream& os);
std::ostream& green(std::ostream& os);
std::ostream& cyan(std::ostream& os);
std::ostream& red(std::ostream& os);
std::ostream& magenta(std::ostream& os);
std::ostream& yellow(std::ostream& os);
std::ostream& white(std::ostream& os);
std::ostream& light_blue(std::ostream& os);
std::ostream& light_green(std::ostream& os);
std::ostream& light_cyan(std::ostream& os);
std::ostream& light_red(std::ostream& os);
std::ostream& light_magenta(std::ostream& os);
std::ostream& light_yellow(std::ostream& os);
std::ostream& light_white(std::ostream& os);
std::ostream& gray(std::ostream& os);
std::ostream& defcolor(std::ostream& os);

// Funkcja, która zwraca manipulator z atrybutami koloru
ColorAttribute setColor(WORD attributes);

#endif // COLOR_MANIP_H