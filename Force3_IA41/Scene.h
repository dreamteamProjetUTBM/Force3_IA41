#pragma once

#include <vector>

#include "Display.h"

class GameObject;

/*
	Classe Scene

	Classe abstraite permettant de cr�er les diff�rentes
	sc�nes du jeu
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
	virtual void update(Display* _disp);
	virtual void draw(Display* _disp);

	sf::String getName();
};

