#include "Button.h"
#include <iostream>

Button::Button(sf::String _name, sf::String _imgNormal, 
	sf::String _imgHover, sf::String _imgPressed,
	std::function<void(SpriteComponent*)> _leftClick,
	std::function<void(SpriteComponent*)> _rightClick,
	std::function<void(SpriteComponent*)> _release) : GameObject(_name)
{
	/* Instantiation des différentes images des états du bouton */
	spriteNormalComp = new SpriteComponent(COMP_SPRITE_NORMAL, _imgNormal);
	spriteHoverComp = new SpriteComponent(COMP_SPRITE_HOVER, _imgHover);
	spritePressedComp = new SpriteComponent(COMP_SPRITE_PRESSED, _imgPressed);

	addComponent(spriteNormalComp);
	addComponent(spriteHoverComp);
	addComponent(spritePressedComp);

	spriteActiveComp = spriteNormalComp;

	clickComp = new ClickableComponent(COMP_CLICK, spriteNormalComp);

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
	spriteNormalComp->setPosition(x, y);
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
	if(!clickComp->isHovered())
	{
		spriteActiveComp = spriteNormalComp;
	}
	else
	{
		spriteActiveComp = spriteHoverComp;

		if (clickComp->isClicked())
		{
			spriteActiveComp = spritePressedComp;
		}
	}

	spriteActiveComp->draw(_disp);
}
