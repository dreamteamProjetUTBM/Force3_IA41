#include "GameObject.h"
#include "Component.h"


GameObject::GameObject()
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
	return false;
}

bool GameObject::removeComponent(sf::String _n)
{
	return false;
}

Component * GameObject::getComponent(sf::String _n)
{
	return nullptr;
}
