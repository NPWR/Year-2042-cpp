#include "EventHandler.h"
#include "Scene.h"

EventHandler::EventHandler(sf::RenderWindow* app, Scene* wrld)
{
    m_WORLD = wrld;
    m_APP = app;

    m_keys.up = false;
    m_keys.down = false;
    m_keys.left =  false;
    m_keys.right = false;
}

EventHandler::~EventHandler()
{
    //dtor
}

void EventHandler::handleEvent(sf::Event ev)
{
    if (ev.type == sf::Event::Closed)
    {
        m_APP->close();
    }
    if (ev.type == sf::Event::KeyPressed)
    {
        if (ev.key.code == sf::Keyboard::Up)
        {
            m_keys.up = true;
        }
        if (ev.key.code == sf::Keyboard::Down)
        {
            m_keys.down = true;
        }
        if (ev.key.code == sf::Keyboard::Left)
        {
            m_keys.left = true;
        }
        if (ev.key.code == sf::Keyboard::Right)
        {
            m_keys.right = true;
        }
    }
    if (ev.type == sf::Event::KeyReleased)
    {
        if (ev.key.code == sf::Keyboard::Up)
        {
            m_keys.up = false;
        }
        if (ev.key.code == sf::Keyboard::Down)
        {
            m_keys.down = false;
        }
        if (ev.key.code == sf::Keyboard::Left)
        {
            m_keys.left = false;
        }
        if (ev.key.code == sf::Keyboard::Right)
        {
            m_keys.right = false;
        }
    }
}

void EventHandler::actEvent()
{
    if (m_keys.up)
    {
        m_WORLD->getCam()->addMov(0,-2);
    }
    if (m_keys.down)
    {
        m_WORLD->getCam()->addMov(0,2);
    }
    if (m_keys.left)
    {
        m_WORLD->getCam()->addMov(-2,0);
    }
    if (m_keys.right)
    {
        m_WORLD->getCam()->addMov(2,0);
    }
}
