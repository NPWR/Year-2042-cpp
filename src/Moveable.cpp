#include "Moveable.h"

Moveable::Moveable()
{
    m_x =  0;
    m_y =  0;
    m_dx = 0;
    m_dy = 0;
    m_drag = 0;
}

Moveable::~Moveable()
{
    //dtor
}

void Moveable::actuate()
{
    mov();
}

void Moveable::mov()
{
    m_x += m_dx;
    m_y += m_dy;
    m_dx *= m_drag;
    m_dy *= m_drag;
}

void Moveable::setDrag(float n)
{
    m_drag = n;
}

void Moveable::addMov(float x, float y)
{
    m_dx += x;
    m_dy += y;
}

sf::Vector2f Moveable::getPos()
{
    return sf::Vector2f(m_x,m_y);
}

sf::Vector2f Moveable::getSpeed()
{
    return sf::Vector2f(m_dx,m_dy);
}
