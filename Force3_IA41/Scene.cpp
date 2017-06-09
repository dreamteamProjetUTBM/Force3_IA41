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

void Scene::update(Display * _disp, sf::Event& _event)
{
	for (auto gameObject : gameObjects)
	{
		gameObject->update(_disp, _event);
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

bool Scene::addGameObject(GameObject * _go)
{
	sf::String name = _go->getName();
	for (auto gameObject : gameObjects)
	{
		if (gameObject->getName() == name)
		{
			return false;
		}
	}

	gameObjects.push_back(_go);

	return true;
}

bool Scene::removeGameObject(sf::String _name)
{
	std::vector<GameObject*>::iterator it;
	int i = 0;
	for (it = gameObjects.begin(); it < gameObjects.end(); it++, i++)
	{
		if (gameObjects[i]->getName() == _name)
		{
			gameObjects.erase(it);
			return true;
		}
	}

	return false;
}

GameObject * Scene::getGameObject(sf::String _name)
{
	for (auto gameObject : gameObjects)
	{
		if (gameObject->getName() == name)
		{
			return gameObject;
		}
	}

	return nullptr;
}
