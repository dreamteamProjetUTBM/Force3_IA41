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

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;

	/* Permet de changer la fonction de callback */
	void setClickedCallback(std::function<void(SpriteComponent*)> _click);
};
