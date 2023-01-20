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
 * File:   GitConnector.cc
 * Author: Javier Marrero
 * 
 * Created on January 19, 2023, 5:01 PM
 */

#include <gippets/GitCommand.h>

// C
#include <sys/types.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <process.h>

// C++
#include <memory>
#include <algorithm>
#include <stdexcept>

using namespace gippets;

GitCommand::GitCommand()
:
m_gitResult(-1)
{
}

GitCommand::~GitCommand()
{

}

void GitCommand::call() const
{
    // Create an array for storing the program arguments
    std::unique_ptr<char*[] > arguments(new char*[m_arguments.size() + 2]);
    arguments[0] = const_cast<char*> (m_command.data());
    arguments[m_arguments.size() + 1] = nullptr;

    // Store the arguments into an array
    for (unsigned i = 0; i < m_arguments.size(); ++i)
    {
        arguments[i + 1] = const_cast<char*> (m_arguments[i].data());
    }

    // Spawn the process
    m_gitResult = spawnvp(P_WAIT, "git", arguments.get());
    if (m_gitResult == -1)
    {
        throw GitCommandException("Unable to open Git!");
    }
}

