#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Moveable.h"
#include "ParticleSystem.h"
#include <SFML/Graphics.hpp>

class Spaceship : public Moveable
{
    public:
        Spaceship();
        virtual ~Spaceship();
        void draw(sf::RenderWindow*, sf::Vector2f);
    protected:
    private:
        ParticleSystem* m_mainRocketParticles;
        ParticleSystem* m_boosterRocketParticles;
};

#endif // SPACESHIP_H
