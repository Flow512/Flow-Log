/*
MIT License

Copyright (c) 2024 Flow

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef FLOW_LOG    //header guard
#define FLOW_LOG

#include <iostream>
#include <Windows.h>
#include <iomanip>

enum class LogLevel {
    INFO           = 11,
    WARNING        = 6,
    ERROR_         = 4,

    BLACK          = 0,
    BLUE           = 1,
    GREEN          = 2,
    CYAN           = 3,
    RED            = 4,
    MAGENTA        = 5,
    ORANGE         = 6,
    LIGHGRAY       = 7,
    DARKGRAY       = 8,
    LIGHTBLUE      = 9,
    LIGHTGREEN     = 10,
    LIGHTCYAN      = 11,
    LIGHTRED       = 12,
    LIGHTMAGENTA   = 13,
    YELLOW         = 14,
    WHITE          = 15
};

class Console
{
private:
    FILE* file;
public:
    Console()
    {
        AllocConsole();
        freopen_s(&file, "CONOUT$", "w", stdout);
    }

    Console(const char* Title)
    {
        AllocConsole();
        freopen_s(&file, "CONOUT$", "w", stdout);

        SetConTitle(Title);
    }

    ~Console() { fclose(file); FreeConsole(); }

    void Destroy() { fclose(file); FreeConsole(); }

    void SetConTitle(const char* Title)
    {
        SetConsoleTitleA(Title);
    }

    void LineSpacer(int Space)
    {
        for (int i = 1; i <= Space; i++)
            std::cout << std::endl;
    }

    void ResetLog() { SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); }

    void ClearLog() { system("cls"); }

    void SetColour(LogLevel lvl) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)lvl); }


    void Title(LogLevel lvl, int Endl, const char* Title, ...)
    {
        va_list Args;
        va_start(Args, Title);

        std::cout << "[";
        SetColour(lvl);

        vprintf(Title, Args);

        SetColour(LogLevel::WHITE);
        std::cout << "]   ";

        LineSpacer(Endl);

        va_end(Args);
    }

    void LogEx(int Endl, const char* Input, ...)
    {
        va_list Args;
        va_start(Args, Input);

        vprintf(Input, Args);

        LineSpacer(Endl);

        va_end(Args);
    }

    void Log(LogLevel lvl, int Endl, const char* Input, ...)
    {
        va_list Args;
        va_start(Args, Input);

        SetColour(lvl);
        vprintf(Input, Args);
        SetColour(LogLevel::WHITE);

        LineSpacer(Endl);

        va_end(Args);
    }

    void LogWT(LogLevel lvl, bool Under, const char* Title_, const char* Input, ...)
    {
        va_list Args;
        va_start(Args, Input);

        Title(lvl, Under, Title_);

        vprintf(Input, Args);

        LineSpacer(1);

        va_end(Args);
    }

    void Report(LogLevel lvl, bool Under, int Endl, const char* Input, ...)
    {
        va_list Args;
        va_start(Args, Input);

        switch (lvl)
        {
        case LogLevel::INFO:
            Title(lvl, Under, "Info");
            break;

        case LogLevel::WARNING:
            Title(lvl, Under, "Warning");
            break;

        case LogLevel::ERROR_:
            Title(lvl, Under, "Error");
            break;
        }

        vprintf(Input, Args);

        LineSpacer(Endl);

        va_end(Args);
    }

    void ShowCursor(bool show)
    {
        HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(ConsoleHandle, &cursorInfo);
        cursorInfo.bVisible = show;
        SetConsoleCursorInfo(ConsoleHandle, &cursorInfo);
    }
};
#endif // !FLOW_LOG

#endif // !FLOW_LOG
