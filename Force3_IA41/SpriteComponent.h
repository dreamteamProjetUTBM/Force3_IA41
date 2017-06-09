#pragma once

#include "Component.h"

/*
	Classe SpriteComponent

	Composant d'affichage pour les GameObjects
*/
class SpriteComponent : Component
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	SpriteComponent(sf::String _name, sf::String _img);
	~SpriteComponent();

	void init(Display* _disp) override;
	void update(Display* _disp) override;
	void draw(Display* _disp) override;

	/* Changer la position du Sprite */
	void setPosition(sf::Vector2f _pos);
	void setPosition(float _x, float _y);
};

