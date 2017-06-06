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
