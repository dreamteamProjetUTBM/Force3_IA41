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
private:
	std::vector<GameObject*> gameObjects;

public:
	Scene();
	virtual ~Scene();

	virtual void init(Display* _disp);
	virtual void update(Display* _disp);
	virtual void draw(Display* _disp);
};

