#ifndef CAMERA_H
#define CAMERA_H

#include <Moveable.h>
#include "Spaceship.h"

class Camera : public Moveable
{
    public:
        Camera();
        virtual ~Camera();
        void follow(Spaceship*);
    protected:
    private:
};

#endif // CAMERA_H
