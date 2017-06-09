#include "Button.h"

Button::Button(sf::String _text) : GameObject(_text)
{
	spriteComp = new SpriteComponent("inactiveSprite", "ressources/case.jpg");
	addComponent(spriteComp);
}

Button::~Button()
{
}

void Button::init(Display * _disp)
{
	GameObject::init(_disp);
}

void Button::update(Display * _disp, sf::Event& _event)
{
	GameObject::update(_disp, _event);
}

void Button::draw(Display * _disp)
{
	GameObject::draw(_disp);
}
