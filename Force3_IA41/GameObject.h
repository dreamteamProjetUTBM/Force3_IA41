#pragma once

#include <vector>

#include "Display.h";

class Component;

/*
	Classe GameObject

	Classe de base de tous les �l�ments du jeu
*/
class GameObject
{
private:
	std::vector<Component*> components;

public:
	GameObject();
	~GameObject();

	virtual void init(Display* _disp);
	virtual void update(Display* _disp);
	virtual void draw(Display* _disp);
};

