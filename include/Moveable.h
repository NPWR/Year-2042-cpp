#include <SFML/Graphics.hpp>

#ifndef MOVEABLE_H
#define MOVEABLE_H

class Moveable
{
    public:
        Moveable();
        virtual ~Moveable();
        void actuate();
        void setDrag(float);
        void addMov(float,float);
        sf::Vector2f getPos();
        sf::Vector2f getSpeed();
        void spdToAng(float,float);

    protected:
        float m_x;
        float m_y;
        float m_dx;
        float m_dy;
        float m_drag;
        float m_angle;
        void mov();
    private:

};

#endif // MOVEABLE_H
