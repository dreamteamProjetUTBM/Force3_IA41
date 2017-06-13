#pragma once
#include "Pawn.h"
#include "GameObject.h"
#include "ClickableComponent.h"

/*
	Classe Case

	GameObject qui représente une case sur le plateau
*/
class Case : public GameObject
{
private:
	/* CONSTANTES */
	const sf::String COMP_SPRITE_INACTIVE = "spriteInact";
	const sf::String COMP_CLICK = "clickComp";

	SpriteComponent* spriteComp;
	ClickableComponent* clickComp;

	Pawn* my_pawn;
	bool _isEmpty;

public:
	Case(sf::String _name,sf::String _image, int x,int y,bool isempty);
	~Case();
	Case &operator=(Case&);

	Pawn* Case::GetPawn();
	void Case::SetPawn(Pawn* value);

	sf::Vector2f getPosition();
	bool isEmpty();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;
};

