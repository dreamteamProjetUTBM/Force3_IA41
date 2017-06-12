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

public:
	TextSpriteComponent(sf::String _name, sf::String _text, sf::String _font);
	~TextSpriteComponent();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;
};
