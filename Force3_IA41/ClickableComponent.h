﻿#pragma once

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
	std::function<void(SpriteComponent*)> leftClicked;
	std::function<void(SpriteComponent*)> rightClicked;
	std::function<void(SpriteComponent*)> released;

	bool isClick;
	bool isHover;

public:
	ClickableComponent(sf::String _name, SpriteComponent* _sprite);
	~ClickableComponent();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;

	/* Permet de changer la fonction de callback pour le clique gauche */
	void setLeftClickedCallback(std::function<void(SpriteComponent*)> _click);
	/* Permet de changer la fonction de callback pour le clique droit */
	void setRightClickCallback(std::function<void(SpriteComponent*)> _click);
	/* Permet de changer la fonction de callback pour le release*/
	void setReleasedCallback(std::function<void(SpriteComponent*)> _real);

	/* Savoir si le bouton est "HOVER" */
	bool isHovered() const;
	/* Savoir sir le bouton est cliqué */
	bool isClicked() const;
};
