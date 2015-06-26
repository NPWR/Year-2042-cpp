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
    for (int i = 0; i < m_stars.size(); i++ )
    {
        for (int j = 0; j < m_stars[i]->size(); j++)
        {
            std::vector<sf::Vector2f> *vec = m_stars[i];
            sf::Vector2f sp = vec->at(j);
            sf::Vector2f nsp;
            float dfac = (i*i)+1;
            nsp.x = sp.x - ((int)campos.x % 1024)/dfac;
            nsp.y = sp.y - ((int)campos.y % 512)/dfac;
            int alph = 255 - 255*i/m_depth;

            sf::CircleShape crc(2);
            crc.setFillColor(sf::Color(255,255,255,alph));
            crc.setPosition(nsp);
            app->draw(crc);
        }
    }
}
