#pragma once

#include "GameObject.h"
#include "SpriteComponent.h"

/*
	Classe Button.

	Gestion de bouton avec actions par le biais d'expression.
*/
class Button : public GameObject
{
private:
	SpriteComponent* spriteComp;

public:
	Button(sf::String _text);
	~Button();

	void init(Display* _disp) override;
	void update(Display* _disp) override;
	void draw(Display* _disp) override;
};

