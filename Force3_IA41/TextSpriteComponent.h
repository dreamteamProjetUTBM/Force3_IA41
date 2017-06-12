#pragma once

#include "Component.h"

/*
 * Classe TextSpriteComponent
 * 
 * Component pour l'affichage d'un texte
 */
class TextSpriteComponent : public Component
{
private:
	sf::Font font;
	sf::Text text;

public:
	TextSpriteComponent(sf::String _name, sf::String _text, sf::String _font);
	~TextSpriteComponent();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;

	/* Changer le texte */
	void setText(sf::String _text);
	/* Changer la couleur d'affichage du texte */
	void setColor(int _r, int _g, int _b);

	/* Méthode pour changer la position */
	void setPosition(sf::Vector2f _pos);
	void setPosition(float _x, float _y);
	/* Méthode pour récupérer la position */
	sf::Vector2f getPosition() const;
};
