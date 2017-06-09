#include "Button.h"

Button::Button(sf::String _text) : GameObject(_text)
{
	spriteComp = new SpriteComponent("inactiveSprite", "resources/btn_inactive.png");
	addComponent(spriteComp);
}

Button::~Button()
{
}

void Button::init(Display * _disp)
{
	GameObject::init(_disp);
}

void Button::update(Display * _disp)
{
	GameObject::update(_disp);
}

void Button::draw(Display * _disp)
{
	GameObject::draw(_disp);
}
