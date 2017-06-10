#pragma once

#include <vector>
#include "Display.h"

class Component;

/*
	Classe GameObject

	Classe de base de tous les éléments du jeu
*/
class GameObject
{
private:
	std::vector<Component*> components;
	sf::String name;

public:
	GameObject(sf::String _name);
	virtual ~GameObject();

	virtual void init(Display* _disp);
	virtual void update(Display* _disp, sf::Event& _event);
	virtual void draw(Display* _disp);

	/* Méthodes utilitaires */
	bool addComponent(Component* _comp);
	bool removeComponent(sf::String _n);
	Component* getComponent(sf::String _n);

	void setName(sf::String value);
	sf::String getName();
};

