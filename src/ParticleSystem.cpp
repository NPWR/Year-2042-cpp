#include "ParticleSystem.h"
#include <string>
#include <unordered_map>
#include <random>
#include <ctime>
#include <cmath>

void verifyColor(int*,int*,int*);

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
    srand(time(NULL));

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

    for ( int i = 0; i < m_particles.size(); i++ )
    {
        //Move particles and select old ones
        std::unordered_map<std::string,float>* particle = m_particles.at(i);
        particle->at("px") += particle->at("dx");
        particle->at("py") += particle->at("dy");
        particle->at("dx") *= m_drag;
        particle->at("dy") *= m_drag;
        particle->at("age") += 1;
        particle->at("size") = (particle->at("bsize")/(m_lifespanBase))*((m_lifespanBase)-(particle->at("age")));
        if ( particle->at("size") < 1 )
        {
            particle->at("size") = 1;
        }
        int mul = rand()%2;
        if ( mul == 0 )
        {
           mul = -1;
        }
        int rnd = (rand()%(int)m_lifespanVar) * mul;
        if ( particle->at("age") > m_lifespanBase + rnd )
        {
            toDelIndexes.emplace(toDelIndexes.begin(),i);
        }
    }
    //Delete old particles
    for ( int i = 0; i < toDelIndexes.size(); i++ )
    {
        m_particles.erase(m_particles.begin() + toDelIndexes[i]);
    }

    if ( m_active )
    {
        //Stop the system if necessary
        if ( (m_stopTime != 0) and (m_time > m_stopTime) )
        {
            stop();
        }

        //Spawn new particles
        for ( int i = 0; i < m_spawnRate; i++)
        {
            int r = rand()%((m_colorBase.r + m_colorRange.r) - (m_colorBase.r - m_colorRange.r)) + (m_colorBase.r - m_colorRange.r);
            int g = rand()%((m_colorBase.g + m_colorRange.g) - (m_colorBase.g - m_colorRange.g)) + (m_colorBase.g - m_colorRange.g);
            int b = rand()%((m_colorBase.b + m_colorRange.b) - (m_colorBase.b - m_colorRange.b)) + (m_colorBase.b - m_colorRange.b);

            float angleDev = (int)(((spread/3.1459)*180)/2);
            int mul = rand()%2;
            if ( mul == 0 )
            {
                 mul = -1;
            }
            angleDev = (rand()%(int)angleDev) * mul;
            angleDev = (angleDev/180) * 3.1459;

            float oAngle = atan2(pmov.y,pmov.x) + 3.1459;
            float nAngle = oAngle + angleDev;

            float spd = hypot(pmov.x,pmov.y) * ((rand()%50 + 50)/100);
            float dx = cos(nAngle) * spd;
            float dy = sin(nAngle) * spd;

            verifyColor(&r,&g,&b);

            float size = rand()%(int)(m_maxsize - m_minsize) + m_minsize;

            newParticle(opos.x,opos.y,omov.x+dx,omov.y+dy,0,(float)r,(float)g,(float)b,size,size);
        }
    }
    m_time++;
}

void ParticleSystem::newParticle(float px, float py, float dx, float dy, float age, float r, float g, float b, float size, float bsize)
{
    std::unordered_map<std::string, float>* particle = new std::unordered_map<std::string, float>;
    particle->emplace("px",px);
    particle->emplace("py",py);
    particle->emplace("dx",dx);
    particle->emplace("dy",dy);
    particle->emplace("age",age);
    particle->emplace("r",r);
    particle->emplace("g",g);
    particle->emplace("b",b);
    particle->emplace("size",size);
    particle->emplace("bsize",bsize);

    m_particles.push_back(particle);
}

void ParticleSystem::draw(sf::RenderWindow* app, sf::Vector2f cp)
{
    for ( int i = 0; i < m_particles.size(); i++)
    {
        std::unordered_map<std::string, float>* p = m_particles[i];
        sf::Vector2f dp(p->at("px")-cp.x, p->at("py")-cp.y);
        sf::CircleShape crc(p->at("size"));
        crc.setPosition(dp);
        crc.setFillColor(sf::Color(p->at("r"),p->at("g"),p->at("b")));
        app->draw(crc);

    }
}

void verifyColor(int *r, int *g, int *b)
{
    if ( *r < 0 )
    {
        *r = 0;
    }
    if ( *r > 255 )
    {
        *r = 255;
    }
    if ( *g < 0 )
    {
        *g = 0;
    }
    if ( *g > 255 )
    {
        *g = 255;
    }
    if ( *b < 0 )
    {
        *b = 0;
    }
    if ( *b > 255 )
    {
        *b = 255;
    }
}
