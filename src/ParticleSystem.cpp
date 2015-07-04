#include "ParticleSystem.h"
#include <string>
#include <unordered_map>

ParticleSystem::ParticleSystem(sf::Color color, sf::Color colorrange, float medLs, float varLs, float minsize, float maxsize)
{
    m_colorBase = color;
    m_colorRange = colorrange;
    m_lifespanBase = medLs,
    m_lifespanVar = varLs;
    m_minsize = minsize;
    m_maxsize = maxsize;
    m_active = false;
    m_time = 0;
    m_stopTime = 0;
    m_spawnRate = 0;
    m_drag = 1.0;

}
ParticleSystem::~ParticleSystem()
{
    //dtor
}

void ParticleSystem::setDrag(float drag)
{
    m_drag = drag;
}

void ParticleSystem::start(int flux, int stop)
{
    if (not m_active)
    {
        m_active = true;
        m_time = 0;
        if (stop != 0)
        {
            m_stopTime = stop;
        }
        m_spawnRate = flux;
    }
}

void ParticleSystem::stop()
{
    if (m_active)
    {
        m_active = false,
        m_time = 0;
        m_stopTime = 0;
        m_spawnRate = 0;
    }
}

void ParticleSystem::actuate(sf::Vector2f opos, sf::Vector2f omov, sf::Vector2f pmov, float spread)
{
    std::vector<int> toDelIndexes;

    for (int i = 0; i < m_particles.size(); i++)
    {
        std::unordered_map<std::string,float> particle = *m_particles.at(i);
        particle["px"] += particle["dx"];
        particle["py"] += particle["dy"];
        particle["dx"] *= m_drag;
        particle["dy"] *= m_drag;
        particle["age"] += 1;
        particle["size"] = (particle["bsize"]/(m_lifespanBase))*((m_lifespanBase)-(particle["age"]));
        if (particle["size"] < 1)
        {
            particle["size"] = 1;
        }

    }
}
