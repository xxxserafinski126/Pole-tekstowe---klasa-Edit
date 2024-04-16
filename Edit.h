#ifndef EDIT_H
#define EDIT_H

#include <string>
#include <conio.h>
#include <windows.h>

class Edit {
public:
    enum Color {
        Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
        LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
    };

    Edit();
    Edit(const Edit& other);
    ~Edit();

    void setPosition(int x, int y);
    void setLength(unsigned int len);
    void setText(const std::string& text);
    void setTextColor(Color color);
    void setBackgroundColor(Color color);
    std::string getText() const;
    void userText();

private:
    std::string text;
    int x, y;
    unsigned int length;
    Color textColor;
    Color backgroundColor;
    HANDLE hConsole;
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

    void applyColors();
    void clear();
};

#endif // EDIT_H