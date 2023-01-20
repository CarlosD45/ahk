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
#include <ncurses/ncurses.h>

// C++
#include <utility>

using namespace gippets;

Console::Console()
{
    initscr();              // Start ncurses mode
    cbreak();               // Disable buffering
    keypad(stdscr, TRUE);   // We need that nifty F1, F2, F3...   
}

Console::~Console()
{
    endwin();
}

Console::point_t Console::getCenterCoordinate()
{
    int x = LINES / 2;
    int y = COLS / 2;

    return std::make_pair(x, y);
}


