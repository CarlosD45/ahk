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
 * File:   Console.h
 * Author: Javier Marrero
 *
 * Created on January 19, 2023, 4:54 PM
 */

#ifndef CONSOLE_H
#define CONSOLE_H

// C++
#include <utility>

// Windows
#ifdef _WIN32
#include <windows.h>
#endif

namespace gippets
{

#define ANSI_CLEAR          L"\033[0m"
#define ANSI_BOLD           L"\033[1m"
#define ANSI_NO_BOLD        L"\033[22m"
#define ANSI_UNDERLINE      L"\033[4m"
#define ANSI_NO_UNDERLINE   L"\033[24m"
#define ANSI_ITALIC         L"\033[3m"
#define ANSI_NO_ITALIC      L"\033[23m"
#define ANSI_DIM            L"\033[2m"
#define ANSI_NO_DIM         L"\033[22m"

#define ANSI_FG_COLOR(ID)   L"\033[38;5;" #ID "m"

class Console
{
public:

    Console();
    ~Console();

    inline int getColumns() const
    {
        return m_columns;
    }

    inline int getLines() const
    {
        return m_lines;
    }

    void clear();
    void drawText(const wchar_t* data);
    void issueCommand(const wchar_t* sequence);
    void moveCursorToLocation(int x, int y);

private:

#    ifdef _WIN32
    HANDLE  m_stdoutHandle;
    DWORD   m_outModeInit;
#    endif

    int m_columns;
    int m_lines;
    
} ;

}

#endif /* CONSOLE_H */

