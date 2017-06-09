#pragma once

#include "Component.h"

/*
	Classe SpriteComponent

	Composant d'affichage pour les GameObjects
*/
class SpriteComponent : public Component
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	SpriteComponent(sf::String _name, sf::String _img);
	~SpriteComponent();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;

	/* Changer la position du Sprite */
	void setPosition(sf::Vector2f _pos);
	void setPosition(float _x, float _y);

	/* Bouger la position du Sprite par l'Offset spécifié */
	void move(sf::Vector2f _posOffset);
	void move(float _xOffset, float _yOffset);

	/* Récupérer la position du Sprite */
	sf::Vector2f getPosition() const;

	/* Récupérer la taille du Sprite */
	sf::Vector2u getSize() const;

	/* Récupérer le rect du Sprite */
	sf::FloatRect getRect() const;
};

