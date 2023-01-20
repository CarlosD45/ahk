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
 * File:   Component.h
 * Author: Javier Marrero
 *
 * Created on January 19, 2023, 11:49 PM
 */

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

// C++
#include <memory>
#include <vector>

// Git-Snippets
#include <gippets/Console.h>

namespace gippets
{

class Component
{
public:

    Component();
    Component(int x, int y, int width, int height);

    virtual ~Component();

    void            add(std::shared_ptr<Component>&& component);
    virtual void    draw(Console& console) const;
    void            moveCursorToOrigin(Console& console) const;

protected:

    int m_x;
    int m_y;
    int m_width;
    int m_height;

    std::vector<std::shared_ptr<Component> >    m_children;
    Component*                                  m_parent;

} ;

}

#endif /* COMPONENT_H */

