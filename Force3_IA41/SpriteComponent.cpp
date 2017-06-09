#include "SpriteComponent.h"
#include <iostream>

SpriteComponent::SpriteComponent(sf::String _name, sf::String _img) : Component(_name)
{
	/* Chargement de la texture */
	if (!texture.loadFromFile(_img))
	{
		std::cout << "[ERROR] Erreur de chargement [IMAGE] : " << _img.toAnsiString() << std::endl;
	}
	else
	{
		std::cout << "[OK] chargement [IMAGE] : " << _img.toAnsiString() << std::endl;
		sprite.setTexture(texture);
	}
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::init(Display * _disp)
{
}

void SpriteComponent::update(Display * _disp)
{
}

void SpriteComponent::draw(Display * _disp)
{
}
