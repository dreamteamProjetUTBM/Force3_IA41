#include "Button.h"

Button::Button(sf::String _text, 
	std::function<void(SpriteComponent*)> _click, 
	std::function<void(SpriteComponent*)> _release) : GameObject(_text)
{
	spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, "ressources/case.png");
	addComponent(spriteComp);

	clickComp = new ClickableComponent(COMP_CLICK, spriteComp);
	clickComp->setClickedCallback(_click);
	clickComp->setReleasedCallback(_release);
	addComponent(clickComp);
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
