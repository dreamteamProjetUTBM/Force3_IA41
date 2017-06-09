#pragma once

#include <functional>

#include "SpriteComponent.h"

/*
 * Classe ClickableComponent
 * 
 * Gestion des clickSouris sur un SpriteComponent d'un
 * GameObject.
 */
class ClickableComponent : public Component
{
private:
	SpriteComponent* sc;
	std::function<void(SpriteComponent*)> clicked;

public:
	ClickableComponent(sf::String _name, SpriteComponent* _sprite);
	~ClickableComponent();
	
	/* Permet de changer la fonction de callback */
	void setClickedCallback(std::function<void(SpriteComponent*)> _click);
};
