#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Background.h"
#include "Spaceship.h"

#include <SFML/Graphics.hpp>

class Scene
{
    public:
        Scene();
        virtual ~Scene();
        void linkCamera(Camera*);
        void newCamera();
        Camera *getCam();
        void newBackground(int,int);
        void newPlayer();
        Spaceship *getPlayer();
        void draw(sf::RenderWindow*);
        void actuate();

    protected:
    private:
        Camera *m_cam;
        Background *m_bg;
        Spaceship *m_player;

};

#endif // SCENE_H
