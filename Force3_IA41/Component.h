#pragma once

#include "GameObject.h"

/*
	Classe Component

	Classe de base des composants qui composent les GameObjects
*/
class Component
{
public:
	Component();
	~Component();

	virtual void init(Display* _disp) = 0;
	virtual void update(Display* _disp) = 0;
	virtual void draw(Display* _disp) = 0;
};

