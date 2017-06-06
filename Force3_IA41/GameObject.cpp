#include "GameObject.h"
#include "Component.h"


GameObject::GameObject(sf::String _name) : name(_name)
{
}


GameObject::~GameObject()
{
}

void GameObject::init(Display * _disp)
{
	for (auto component : components)
	{
		component->init(_disp);
	}
}

void GameObject::update(Display * _disp)
{
	for(auto component : components)
	{
		component->update(_disp);
	}
}

void GameObject::draw(Display * _disp)
{
	for (auto component : components)
	{
		component->draw(_disp);
	}
}

bool GameObject::addComponent(Component * _comp)
{
	sf::String n = _comp->getName();
	for (auto component : components)
	{
		if (component->getName() == n)
			return false;
	}

	components.push_back(_comp);
	return true;
}

bool GameObject::removeComponent(sf::String _n)
{
	std::vector<Component*>::iterator it;
	int i = 0;
	for (it = components.begin(); it < components.end(); it++, i++)
	{
		if (components[i]->getName() == _n)
		{
			components.erase(it);
			return true;
		}
	}

	return false;
}

Component * GameObject::getComponent(sf::String _n)
{
	for (auto component : components)
	{
		if (component->getName() == _n)
		{
			return component;
		}
	}

	return nullptr;
}

sf::String GameObject::getName()
{
	return name;
}
