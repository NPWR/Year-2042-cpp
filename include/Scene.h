#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"
#include "Background.h"

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
        void draw(sf::RenderWindow*);

    protected:
    private:
        Camera *m_cam;
        Background *m_bg;
};

#endif // SCENE_H
