#pragma once

#include "GameObject.h"

/*
	Classe Component

	Classe de base des composants qui composent les GameObjects
*/
class Component
{
protected:
	sf::String name;

public:
	Component(sf::String _name);
	~Component();

	virtual void init(Display* _disp) = 0;
	virtual void update(Display* _disp, sf::Event& _event) = 0;
	virtual void draw(Display* _disp) = 0;

	sf::String getName();
};

