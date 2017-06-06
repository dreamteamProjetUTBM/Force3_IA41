#pragma once

#include "Display.h"

/*
	Classe Scene

	Classe abstraite permettant de créer les différentes
	scènes du jeu
*/
class Scene
{
private:

public:
	Scene();
	virtual ~Scene();

	virtual void init(Display* _disp) = 0;
	virtual void update(Display* _disp) = 0;
	virtual void draw(Display* _disp) = 0;
};

