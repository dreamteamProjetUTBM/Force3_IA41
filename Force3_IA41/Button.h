#pragma once

#include "GameObject.h"
#include "ClickableComponent.h"

/*
	Classe Button.

	Gestion de bouton avec actions par le biais d'expression.
*/
class Button : public GameObject
{
private:
	/* CONSTANTES */
	const sf::String COMP_SPRITE_NORMAL = "spriteNormal";
	const sf::String COMP_SPRITE_HOVER = "spriteHover";
	const sf::String COMP_SPRITE_PRESSED = "spritePressed";

	const sf::String COMP_CLICK = "clickComp";

	SpriteComponent* spriteNormalComp;
	SpriteComponent* spriteHoverComp;
	SpriteComponent* spritePressedComp;
	ClickableComponent* clickComp;

public:
	Button(sf::String _name, sf::String _imgNormal, sf::String _imgHover, sf::String _imgPressed, std::function<void(SpriteComponent*)> _leftClick,
		std::function<void(SpriteComponent*)> _rightClick,
		std::function<void(SpriteComponent*)> _release);
	~Button();

	void setPosition(int x, int y);

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;
};

