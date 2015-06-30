#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Moveable.h"
#include <SFML/Graphics.hpp>

class Spaceship : public Moveable
{
    public:
        Spaceship();
        virtual ~Spaceship();
        void draw(sf::RenderWindow*, sf::Vector2f);
    protected:
    private:
};

#endif // SPACESHIP_H
