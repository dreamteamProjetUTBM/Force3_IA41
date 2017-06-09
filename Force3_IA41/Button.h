#pragma once

#include "GameObject.h"

/*
	Classe Button.

	Gestion de bouton avec actions par le biais d'expression.
*/
class Button : GameObject
{
private:

public:
	Button(sf::String _text);
	~Button();
};

