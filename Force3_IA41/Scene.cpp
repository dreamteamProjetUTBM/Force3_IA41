#include "Scene.h"
#include "GameObject.h"

Scene::Scene(sf::String _name) : name(_name)
{
}

Scene::~Scene()
{
}

void Scene::init(Display * _disp)
{
	for (auto gameObject : gameObjects)
	{
		gameObject->init(_disp);
	}
}

void Scene::update(Display * _disp)
{
	for (auto gameObject : gameObjects)
	{
		gameObject->update(_disp);
	}
}

void Scene::draw(Display * _disp)
{
	for (auto gameObject : gameObjects)
	{
		gameObject->draw(_disp);
	}
}

sf::String Scene::getName()
{
	return name;
}
