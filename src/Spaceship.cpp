#include "Spaceship.h"
#include <SFML/Graphics.hpp>

Spaceship::Spaceship() : Moveable()
{
    setDrag(0.95);
}

Spaceship::~Spaceship()
{
    //dtor
}

void Spaceship::draw(sf::RenderWindow *app, sf::Vector2f cp)
{
    sf::Vector2f dp(m_x - cp.x, m_y - cp.y);

    sf::CircleShape bodyCircle(10);
    bodyCircle.setPosition(dp);
    bodyCircle.setOutlineColor(sf::Color(255,255,255));
    bodyCircle.setFillColor(sf::Color(0,0,0));
    bodyCircle.setOutlineThickness(1);

    app->draw(bodyCircle);
}
