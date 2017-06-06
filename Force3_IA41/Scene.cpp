#include "Scene.h"
#include "GameObject.h"

Scene::Scene()
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
