#pragma once

#include "Component.h"

/*
	Classe SpriteComponent

	Composant d'affichage pour les GameObjects
*/
class SpriteComponent : Component
{
public:
	SpriteComponent(sf::String _name, sf::String _img);
	~SpriteComponent();
};

