#include "Camera.h"
#include "Moveable.h"
#include "Spaceship.h"

#include <SFML/Graphics.hpp>

Camera::Camera() : Moveable()
{

}

Camera::~Camera()
{
    //dtor
}

void Camera::follow(Spaceship *plyr)
{
    sf::VideoMode scrSize(sf::VideoMode::getDesktopMode());
    int W = scrSize.width;
    int H = scrSize.height;

    sf::Vector2f plyrPos(plyr->getPos());
    m_x = plyrPos.x - W/2;
    m_y = plyrPos.y - H/2;
}
