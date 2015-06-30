#include "Scene.h"
#include "Camera.h"
#include "Spaceship.h"

Scene::Scene()
{
    m_cam = NULL;
    m_bg = NULL;
    m_player = NULL;
}

Scene::~Scene()
{
    delete m_cam;
}

void Scene::linkCamera(Camera *cam)
{
    m_cam = cam;
}

void Scene::newCamera()
{
    delete m_cam;
    m_cam = new Camera;
}

Camera* Scene::getCam()
{
    return m_cam;
}

void Scene::newBackground(int dpt, int dens)
{
    m_bg = new Background(dpt,dens);
}

void Scene::draw(sf::RenderWindow* app)
{
    sf::Vector2f campos(m_cam->getPos());
    m_bg->draw(app, campos);
    m_player->draw(app,campos);
}

void Scene::actuate()
{
    m_cam->actuate();
    m_player->actuate();
}

void Scene::newPlayer()
{
    m_player = new Spaceship;
}

Spaceship *Scene::getPlayer()
{
    return m_player;
}
