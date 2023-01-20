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
 * File:   GitConnector.h
 * Author: Javier Marrero
 *
 * Created on January 19, 2023, 5:01 PM
 */

#ifndef GITCONNECTOR_H
#define GITCONNECTOR_H

// C++
#include <cstdint>
#include <exception>
#include <string>
#include <vector>

namespace gippets
{

class GitCommand
{
public:

    class GitCommandException : public std::exception
    {
    public:

        GitCommandException(const std::string& message) : m_message(message) { }

    private:

        std::string m_message;
    } ;

    GitCommand();
    ~GitCommand();

    /**
     * Adds an argument to the Git command.
     *
     * @param argument
     */
    inline void addArgument(std::string&& argument)
    {
        m_arguments.push_back(argument);
    }

    /**
     * Calls git with the specified command line parameters.
     */
    void call() const;

    /**
     * Returns the result to the call to Git.
     * 
     * @return
     */
    inline intptr_t getResult()
    {
        return m_gitResult;
    }

    /**
     * Sets the command for the git executable... (i.e add, commit)
     *
     * @param command
     */
    inline void setCommand(const std::string& command)
    {
        m_command = command;
    }

private:

    std::vector<std::string>    m_arguments;
    std::string                 m_command;
    mutable std::intptr_t       m_gitResult;

} ;

}

#endif /* GITCONNECTOR_H */

