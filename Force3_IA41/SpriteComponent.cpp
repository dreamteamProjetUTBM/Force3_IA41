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

void SpriteComponent::update(Display * _disp, sf::Event& _event)
{
}

void SpriteComponent::draw(Display * _disp)
{
	_disp->draw(&sprite);
}

void SpriteComponent::setPosition(sf::Vector2f _pos)
{
	sprite.setPosition(_pos);
}

void SpriteComponent::setPosition(float _x, float _y)
{
	sprite.setPosition(_x, _y);
}

void SpriteComponent::move(sf::Vector2f _posOffset)
{
	sprite.move(_posOffset);
}

void SpriteComponent::move(float _xOffset, float _yOffset)
{
	sprite.move(_xOffset, _yOffset);
}

sf::Vector2f SpriteComponent::getPosition() const
{
	return sprite.getPosition();
}
