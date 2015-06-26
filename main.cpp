#include <iostream>
#include <SFML/Graphics.hpp>
#include "Camera.h"

using namespace sf;

int main()
{
    RenderWindow app(VideoMode(1024,500,32),"Hello !");
    app.setFramerateLimit(60);
    app.setVerticalSyncEnabled(true);

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

    app.display();
    }
}
