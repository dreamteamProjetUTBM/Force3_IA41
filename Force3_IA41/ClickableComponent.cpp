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
	bool inside = sc->getRect().contains(_event.mouseMove.x, _event.mouseMove.y);	

	if(inside)
	{
		/* Dans le cas du click GAUCHE */
		if(_event.type == sf::Event::MouseButtonPressed && 
			_event.mouseButton.button == sf::Mouse::Left)
		{
			if(!isClick)
			{
				std::cout << "click" << std::endl;
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
				std::cout << "click" << std::endl;
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
	else if(!inside)
	{
		if(isClick)
		{
			released(sc);
			isClick = false;
		}
	}
}

void ClickableComponent::draw(Display* _disp)
{
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
