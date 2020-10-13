#include "Graphic.h"
string Graphic::transPassword()
{
    string password;
    char temp = 0;
    while (true)
    {
        temp = _getch();
        if (temp == 13)
            break;
        if ((int)temp == 8) {
            password = password.substr(0, password.length() - 1);
        }
        else {
            password = password + temp;
        }
        cout << '\r';
        for (int i = 0; i <= password.length(); i++)
            cout << ' ';
        cout << '\r';
        for (int i = 0; i < password.length(); i++)
            cout << '*';
    }
    cout << endl;
    return password;
}

void Graphic::changeColour(string s,int colour) {
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
    cout << s;
}

void Graphic::setWidth(int n)
{
    for (int i = 0; i < n; i++)
        cout << "\t";
}

void Graphic::setHeight(int n)
{
    for (int i = 0; i < n; i++)
        cout << "\n";
}

void Graphic::font(int a, int b)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
    lpConsoleCurrentFontEx->dwFontSize.X = a;
    lpConsoleCurrentFontEx->dwFontSize.Y = b;
    SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}
