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
#ifndef FlowLog    //header guard
#define FlowLog

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cstdarg>
#include <string>

enum LogLevel {
    INFO_           = 11,
    WARNING_        = 6,
    ERROR_          = 4,

    _BLACK          = 0,
    _BLUE           = 1,
    _GREEN          = 2,
    _CYAN           = 3,
    _RED            = 4,
    _MAGENTA        = 5,
    _ORANGE         = 6,
    _LIGHGRAY       = 7,
    _DARKGRAY       = 8,
    _LIGHTBLUE      = 9,
    _LIGHTGREEN     = 10,
    _LIGHTCYAN      = 11,
    _LIGHTRED       = 12,
    _LIGHTMAGENTA   = 13,
    _YELLOW         = 14,
    _WHITE          = 15
};

namespace console
{
    inline void SetConTitle(const char* Title)
    {
        SetConsoleTitleA(Title);
    }

    inline void Init()
	{
		AllocConsole();
        freopen("CONOUT$", "w", stdout);
	}

    inline void Init(const char* Title)
    {
        AllocConsole();
        freopen("CONOUT$", "w", stdout);
        console::SetConTitle(Title);
    }

    inline void LineSpacer(int Space)
    {
        for (int i = 1; i <= Space; i++)
            std::cout << std::endl;
    }

    inline void ClearLog()
    {
        system("cls");
    }

    inline void ClearLog(int Delay)
    {
        Sleep(Delay);
        system("cls");
    }

    inline void SetColour(LogLevel lvl)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lvl);
    }

    inline void Title(LogLevel lvl, int Endl, const char* Title, ...)
    {
        va_list Args;
        va_start(Args, Title);
        int pad = 30 - vsnprintf(nullptr, 0, Title, Args);

        console::SetColour(lvl);

        std::cout << "[";
        vprintf(Title, Args);
        std::cout << "] " << std::setw(pad) << "";

        console::LineSpacer(Endl);
        console::SetColour(_WHITE);

        va_end(Args);
    }

    inline void Log(int Endl, const char* Input, ...)
    {
        va_list Args;
        va_start(Args, Input);

        vprintf(Input, Args);

        console::LineSpacer(Endl);

        va_end(Args);
    }

    inline void Log(LogLevel lvl, int Endl, const char* Input, ...)
    {
        va_list Args;
        va_start(Args, Input);

        console::SetColour(lvl);
        vprintf(Input, Args);
        console::SetColour(_WHITE);

        console::LineSpacer(Endl);

        va_end(Args);
    }

    inline void Log(LogLevel lvl, bool Under, const char* Title, const char* Input, ...)
    {
        va_list Args;
        va_start(Args, Input);

        console::Title(lvl, Under, Title);

        vprintf(Input, Args);
        
        console::LineSpacer(1);

        va_end(Args);
    }

    inline void Report(LogLevel lvl, bool Under, int Endl, const char* Input, ...)
	{
        va_list Args;
        va_start(Args, Input);

        switch (lvl)
        {
        case LogLevel::INFO_:
            console::Title(lvl, Under, "Info");
            break;

        case LogLevel::WARNING_:
            console::Title(lvl, Under, "Warning");
            break;

        case LogLevel::ERROR_:
            console::Title(lvl, Under, "Error");
                break;
        }

        vprintf(Input, Args);

        console::LineSpacer(Endl);

        va_end(Args);
	}
}

#endif // !flow_log
