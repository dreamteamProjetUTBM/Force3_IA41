#include "Component.h"



Component::Component(sf::String _name) : name(_name)
{
}


Component::~Component()
{
}

sf::String Component::getName()
{
	return name;
}
