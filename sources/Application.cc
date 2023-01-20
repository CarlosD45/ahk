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
 * File:   Application.cc
 * Author: Javier Marrero
 * 
 * Created on January 19, 2023, 6:56 PM
 */

#include <gippets/Application.h>

// C++
#include <cstdlib>
#include <string>
#include <iostream>
#include <wchar.h>

using namespace gippets;

const wchar_t* const Application::APPLICATION_NAME = L"Git-Snippets v0.2";

Application::Application()
:
m_console(new Console())
{
    // Initialize the screen
    initComponents();
}

Application::~Application()
{
}

void Application::error(const wchar_t* message)
{
    m_console->issueCommand(ANSI_FG_COLOR(203) ANSI_BOLD L"error: " ANSI_CLEAR);
    m_console->drawText(message);
    m_console->drawText(L"\n");
}

void Application::initComponents()
{
    m_mainViewport = std::make_shared<Frame>(m_console->getColumns(), m_console->getLines());

    // Print the initial text
    m_mainViewport->moveCursorToOrigin(*m_console);
    m_console->drawText(L"Git-Snippets v0.2\n");
    m_console->drawText(ANSI_FG_COLOR(198) ANSI_BOLD L":: Welcome to Git-Snippets!\n" ANSI_CLEAR);
    m_console->drawText(ANSI_BOLD "Type Ctrl+Z for exit, help for help, and other commands as specified in the help page...\n\n" ANSI_NO_BOLD);

}

int Application::mainloop()
{
    while (true)
    {
        // Get input
        prompt();

        std::wstring input;
        std::getline(std::wcin, input);

        // Process the input message
        if (input == L"q" || input == L"quit")
        {
            return EXIT_SUCCESS;
        }
        else
        {
            if (input != L"")
            {
                wchar_t buffer[0x400] = {0};
                std::swprintf(buffer, L"unrecognized command: %S", input.c_str());

                error(buffer);
            }
        }

        // Redraw
        m_mainViewport->draw(*m_console);
    }
    return EXIT_SUCCESS;
}

void Application::prompt()
{
    m_console->drawText(ANSI_FG_COLOR(45) ANSI_BOLD "> " ANSI_CLEAR);
}


