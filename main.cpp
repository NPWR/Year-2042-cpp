#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Scene.h"

using namespace sf;

int main()
{
    RenderWindow app(VideoMode(1368,768,32),"Hello !",Style::Fullscreen);
    app.setFramerateLimit(60);
    app.setVerticalSyncEnabled(true);

    Scene WORLD;
    WORLD.newCamera();
    WORLD.getCam()->setDrag(0.95);
    WORLD.newBackground(10,10);

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                app.close();
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                {
                    WORLD.getCam()->addMov(0,-5);
                }
                if (event.key.code == Keyboard::Down)
                {
                    WORLD.getCam()->addMov(0,5);
                }
                if (event.key.code == Keyboard::Left)
                {
                    WORLD.getCam()->addMov(-5,0);
                }
                if (event.key.code == Keyboard::Right)
                {
                    WORLD.getCam()->addMov(5,0);
                }
            }
        }
    app.clear();
    WORLD.actuate();
    WORLD.draw(&app);
    app.display();
    }
}
