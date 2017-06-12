#include "ClickableComponent.h"
#include <iostream>

ClickableComponent::ClickableComponent(sf::String _name, SpriteComponent* _sprite) : Component(_name)
{
	sc = _sprite;
	isClick = false;
}

ClickableComponent::~ClickableComponent()
{
}

void ClickableComponent::init(Display* _disp)
{
}

void ClickableComponent::update(Display* _disp, sf::Event& _event)
{
	isHover = sc->getRect().contains(sf::Mouse::getPosition(_disp->getWindow()).x, sf::Mouse::getPosition(_disp->getWindow()).y);

	if(isHover)
	{
		/* Dans le cas du click GAUCHE */
		if(_event.type == sf::Event::MouseButtonPressed && 
			_event.mouseButton.button == sf::Mouse::Left)
		{
			if(!isClick)
			{
				leftClicked(sc);
				isClick = true;
			}
		}
		/* Dans le cas du click DROIT */
		else if(_event.type == sf::Event::MouseButtonPressed &&
			_event.mouseButton.button == sf::Mouse::Right)
		{
			if (!isClick)
			{
				rightClicked(sc);
				isClick = true;
			}
		}
		/* Dans tous les autres cas */
		else
		{
			if (isClick)
			{
				released(sc);
				isClick = false;
			}
		}
	}
	else if(!isHover)
	{
		if(isClick)
		{
			isClick = false;
		}
	}
}

void ClickableComponent::draw(Display* _disp)
{
	/* Pas de dessin pour ce component */
}

void ClickableComponent::setLeftClickedCallback(std::function<void(SpriteComponent*)> _click)
{
	leftClicked = _click;
}

void ClickableComponent::setRightClickCallback(std::function<void(SpriteComponent*)> _click)
{
	rightClicked = _click;
}

void ClickableComponent::setReleasedCallback(std::function<void(SpriteComponent*)> _real)
{
	released = _real;
}

bool ClickableComponent::isHovered() const
{
	return isHover;
}

bool ClickableComponent::isClicked() const
{
	return isClick;
}
