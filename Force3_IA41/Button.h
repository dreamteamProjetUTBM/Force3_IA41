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
	const sf::String COMP_SPRITE_INACTIVE = "spriteInact";
	const sf::String COMP_CLICK = "clickComp";

	SpriteComponent* spriteComp;
	ClickableComponent* clickComp;

public:
	Button(sf::String _text, std::function<void(SpriteComponent*)> _click, std::function<void(SpriteComponent*)> _release);
	~Button();

	void setPosition(int x, int y);

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;
};

