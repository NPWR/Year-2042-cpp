#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Scene.h"
#include "EventHandler.h"

using namespace sf;

int main()
{
    RenderWindow app(VideoMode(1360,768,32),"Hello !",Style::Fullscreen);
    app.setFramerateLimit(60);
    app.setVerticalSyncEnabled(true);

    Scene WORLD;
    WORLD.newCamera();
    WORLD.getCam()->setDrag(0.95);
    WORLD.newBackground(10,10);
    WORLD.newPlayer();

    EventHandler evHand(&app, &WORLD);

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            evHand.handleEvent(event);
        }
    app.clear();
    evHand.actEvent();
    WORLD.actuate();
    WORLD.getCam()->follow(WORLD.getPlayer());
    WORLD.draw(&app);
    app.display();
    }
}
