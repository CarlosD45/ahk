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
 * File:   Application.h
 * Author: Javier Marrero
 *
 * Created on January 19, 2023, 6:56 PM
 */

#ifndef APPLICATION_H
#define APPLICATION_H

// Git-Snippets
#include <gippets/Console.h>
#include <gippets/Window.h>

// C++
#include <memory>

namespace gippets
{

class Application
{
public:

    Application();
    ~Application();

    void initComponents();

    /**
     * Infinite loops go brrr...
     */
    void run();

private:

    static const char* const APPLICATION_NAME;

    std::shared_ptr<Console>    m_console;
    std::shared_ptr<Window>     m_window;

} ;

}

#endif /* APPLICATION_H */

