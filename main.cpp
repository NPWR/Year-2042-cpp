#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Scene.h"

using namespace sf;

int main()
{
    RenderWindow app(VideoMode(1024,512,32),"Hello !");
    app.setFramerateLimit(60);
    app.setVerticalSyncEnabled(true);

    Scene WORLD;
    WORLD.newCamera();
    WORLD.newBackground(10,15);

    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                app.close();
            }
        }
    app.clear();
    WORLD.draw(&app);
    app.display();
    }
}
