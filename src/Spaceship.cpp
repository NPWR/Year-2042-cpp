#include "Spaceship.h"
#include <SFML/Graphics.hpp>
#include <cmath>

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

    sf::CircleShape rear(4);
    sf::CircleShape rear2(4);

    sf::Vector2f r1p;
    sf::Vector2f r2p;
    r1p.x = 10*cos(m_angle + 3.149/4) + dp.x + 7;
    r1p.y = 10*sin(m_angle + 3.149/4) + dp.y + 6;
    r2p.x = 10*cos(m_angle - 3.149/4) + dp.x + 7;
    r2p.y = 10*sin(m_angle - 3.149/4) + dp.y + 6;

    rear.setPosition(r1p);
    rear2.setPosition(r2p);

    rear.setFillColor(sf::Color(0,0,0));
    rear.setOutlineColor(sf::Color(255,255,255));
    rear.setOutlineThickness(1);

    rear2.setFillColor(sf::Color(0,0,0));
    rear2.setOutlineColor(sf::Color(255,255,255));
    rear2.setOutlineThickness(1);

    app->draw(rear);
    app->draw(rear2);

    //Big Center circle drawing
    sf::CircleShape bodyCircle(10);
    bodyCircle.setPosition(dp);
    bodyCircle.setOutlineColor(sf::Color(255,255,255));
    bodyCircle.setFillColor(sf::Color(0,0,0));
    bodyCircle.setOutlineThickness(1);

    app->draw(bodyCircle);
}
