#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class ParticleSystem
{
    public:
        ParticleSystem(sf::Color,sf::Color,float,float,float,float);
        virtual ~ParticleSystem();
        void setDrag(float);
        void start(int,int);
        void stop();
        void actuate(sf::Vector2f,sf::Vector2f, sf::Vector2f, float);
        void draw(sf::RenderWindow*, sf::Vector2f);
    protected:
    private:
        sf::Color m_colorBase;
        sf::Color m_colorRange;
        float m_lifespanBase;
        float m_lifespanVar;
        float m_minsize;
        float m_maxsize;
        bool m_active;
        int m_time;
        int m_stopTime;
        int m_spawnRate;
        int m_drag;
        std::vector<std::unordered_map<std::string, float>*> m_particles;
        void newParticle(float,float,float,float,float,float,float,float,float,float);

};

#endif // PARTICLESYSTEM_H
