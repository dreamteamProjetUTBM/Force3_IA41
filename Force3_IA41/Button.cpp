#include "Button.h"

Button::Button(sf::String _text) : GameObject(_text)
{
	spriteComp = new SpriteComponent("inactiveSprite", "resources/btn_inactive.png");
	addComponent(spriteComp);
}

Button::~Button()
{
}
