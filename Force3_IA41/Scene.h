#pragma once

#include <vector>

#include "Display.h"

class GameObject;

/*
	Classe Scene

	Classe abstraite permettant de créer les différentes
	scènes du jeu
*/
class Scene
{
protected:
	std::vector<GameObject*> gameObjects;
	sf::String name;

public:
	Scene(sf::String _name);
	virtual ~Scene();

	virtual void init(Display* _disp);
	virtual void update(Display* _disp, sf::Event& _event);
	virtual void draw(Display* _disp);

	sf::String getName();

	bool addGameObject(GameObject* _go);
	bool removeGameObject(sf::String _name);
	GameObject* getGameObject(sf::String _name);
};

