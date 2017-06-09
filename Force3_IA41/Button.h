#pragma once

#include "GameObject.h"
#include "SpriteComponent.h"

/*
	Classe Button.

	Gestion de bouton avec actions par le biais d'expression.
*/
class Button : GameObject
{
private:
	SpriteComponent* spriteComp;

public:
	Button(sf::String _text);
	~Button();
};

