/*
 * The MIT License
 *
 * Copyright 2023 Javier Marrero.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   Console.cc
 * Author: Javier Marrero
 * 
 * Created on January 19, 2023, 4:54 PM
 */

#include <gippets/Console.h>

// C++
#include <cstdio>
#include <stdexcept>
#include <wchar.h>

#ifdef _WIN32
#    ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#        define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#    endif
#endif

using namespace gippets;

Console::Console()
{
    /*
     * If we are under Windows, get the handles and all that stuff
     */
#ifdef _WIN32
    m_stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

    /*
     * Query number of lines and columns
     */
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(m_stdoutHandle, &csbi);
    m_columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    m_lines = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#endif

    /**
     * Enable ANSI Terminal Scape Code Processing
     */
#ifdef _WIN32
    DWORD outMode = 0;

    if (m_stdoutHandle == INVALID_HANDLE_VALUE)
    {
        throw std::runtime_error("invalid handle value");
    }

    if (!GetConsoleMode(m_stdoutHandle, &outMode))
    {
        throw std::runtime_error("invalid console mode.");
    }

    m_outModeInit = outMode;
    outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(m_stdoutHandle, outMode))
    {
        throw std::runtime_error("unable to set console mode.");
    }
#endif

}

Console::~Console()
{
    std::wprintf(L"\033[0m");

#ifdef _WIN32
    if (!SetConsoleMode(m_stdoutHandle, m_outModeInit))
    {
        exit(GetLastError());
    }
#endif
}

void Console::clear()
{
#ifdef _WIN32
    DWORD   written     = 0;
    PCWSTR  sequence    = L"\x1b[2J";
    WriteConsoleW(m_stdoutHandle, sequence, (DWORD) std::wcslen(sequence), &written, NULL);
#endif
}

void Console::drawText(const wchar_t* data)
{
    std::wprintf(data);
}

void Console::moveCursorToLocation(int x, int y)
{
    wchar_t sequence[64] = {0};
    std::swprintf(sequence, L"\033[%d;%df", y, x);
}

void Console::issueCommand(const wchar_t* sequence)
{
    std::wprintf(sequence);
}
