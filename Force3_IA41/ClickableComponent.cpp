#include "ClickableComponent.h"

ClickableComponent::ClickableComponent(sf::String _name, SpriteComponent* _sprite) : Component(_name)
{
	sc = _sprite;
}

ClickableComponent::~ClickableComponent()
{
}

void ClickableComponent::setClickedCallback(std::function<void(SpriteComponent*)> _click)
{
	clicked = _click;
}
