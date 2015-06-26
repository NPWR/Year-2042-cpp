#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background
{
    public:
        Background(int,int);
        virtual ~Background();
        void draw(sf::RenderWindow*, sf::Vector2f);
    protected:
    private:
        std::vector<std::vector<sf::Vector2f>*> m_stars;
        int m_depth;
        int m_density;
};

#endif // BACKGROUND_H
