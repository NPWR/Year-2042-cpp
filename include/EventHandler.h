#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SFML/Graphics.hpp>
#include "Scene.h"

struct keyStructure{
    int up;
    int down;
    int left;
    int right; };

class EventHandler
{
    public:
        EventHandler(sf::RenderWindow*, Scene*);
        virtual ~EventHandler();
        void handleEvent(sf::Event);
        void actEvent();
    protected:
    private:
        Scene *m_WORLD;
        sf::RenderWindow *m_APP;
        struct keyStructure m_keys;
};

#endif // EVENTHANDLER_H
