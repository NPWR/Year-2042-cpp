#include "Spaceship.h"
#include <SFML/Graphics.hpp>
#include <cmath>

#include "ParticleSystem.h"

Spaceship::Spaceship() : Moveable()
{
    setDrag(0.95);
    m_mainRocketParticles = new ParticleSystem(sf::Color(0,255,255),sf::Color(20,20,20),10,5,2,5);
    m_mainRocketParticles->start(10,10);
}

Spaceship::~Spaceship()
{
    //dtor
}

void Spaceship::draw(sf::RenderWindow *app, sf::Vector2f cp)
{
    float mang = atan2(m_dy,m_dx);
    float pmx = cos(mang)*30;
    float pmy = sin(mang)*30;
    m_mainRocketParticles->actuate(sf::Vector2f(m_x,m_y),sf::Vector2f(m_dx,m_dy),sf::Vector2f(pmx,pmy),3.1459/6);

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
    m_mainRocketParticles->draw(app,cp);
}
