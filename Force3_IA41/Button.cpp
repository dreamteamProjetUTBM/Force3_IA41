#include "Button.h"

Button::Button(sf::String _text, 
	std::function<void(SpriteComponent*)> _leftClick,
	std::function<void(SpriteComponent*)> _rightClick,
	std::function<void(SpriteComponent*)> _release) : GameObject(_text)
{
	//spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, "ressources/button_jouer.png");
	spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, "ressources/button_jouer.png");

	addComponent(spriteComp);

	clickComp = new ClickableComponent(COMP_CLICK, spriteComp);

	/* Ajout des différents Callback pour le component ClickableComponent */
	clickComp->setLeftClickedCallback(_leftClick);
	clickComp->setRightClickCallback(_rightClick);
	clickComp->setReleasedCallback(_release);
	addComponent(clickComp);
}



Button::~Button()
{
}

void Button::setPosition(int x, int y)
{
	spriteComp->setPosition(x, y);
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
