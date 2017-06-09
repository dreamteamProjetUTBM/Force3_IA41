#include "ClickableComponent.h"

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
		if(_event.type == sf::Event::MouseButtonPressed)
		{
			if(!isClick)
			{
				clicked(sc);
				isClick = true;
			}
		}
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

void ClickableComponent::setClickedCallback(std::function<void(SpriteComponent*)> _click)
{
	clicked = _click;
}

void ClickableComponent::setReleasedCallback(std::function<void(SpriteComponent*)> _real)
{
	released = _real;
}
