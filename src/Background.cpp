#include <SFML/Graphics.hpp>
#include "Background.h"
#include <random>

Background::Background(int dpt, int dens)
{
    m_depth = dpt;
    m_density = dens;
    //Stars container vectors init
    for (int plan = 0; plan<dpt; plan++)
    {
        m_stars.push_back(new std::vector<sf::Vector2f>);
        for(int star = 0; star<dens; star++)
        {
            float x = rand()%1024;
            float y = rand()%512;
            m_stars[plan]->push_back(sf::Vector2f(x,y));
        }
    }
}

Background::~Background()
{
    //dtor
}

void Background::draw(sf::RenderWindow* app, sf::Vector2f campos)
{

}
