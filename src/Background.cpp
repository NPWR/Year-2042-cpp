#include <SFML/Graphics.hpp>
#include "Background.h"
#include <random>
#define EUCMOD(a, b)  (a < 0 ? (((a % b) + b) % b) : (a % b))

sf::VideoMode windowdevice = sf::VideoMode::getDesktopMode();
int W = windowdevice.width;
int H = windowdevice.height;

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
            float x = rand()%W;
            float y = rand()%H;
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
        std::vector<sf::Vector2f> *vec = m_stars[i];
        float dmod = (i*i)+1;
        int alph = 255 - 255*i/m_depth;

        for (int j = 0; j < m_stars[i]->size(); j++)
        {
            sf::Vector2f sp = vec->at(j);
            sf::Vector2f nsp;

            nsp.x = EUCMOD((int)(sp.x - campos.x/dmod),W);
            nsp.y = EUCMOD((int)(sp.y - campos.y/dmod),H);

            sf::CircleShape crc(2);
            crc.setFillColor(sf::Color(255,255,255,alph));
            crc.setPosition(nsp);
            app->draw(crc);
        }
    }
}
