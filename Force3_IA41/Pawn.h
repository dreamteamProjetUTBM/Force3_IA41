#pragma once
#include "GameObject.h"
#include "ClickableComponent.h"

/*
	Classe Pawn

	GameObject qui représente un pion de jeu
*/
class Pawn : public GameObject
{
private:
	/* CONSTANTES */
	const sf::String COMP_SPRITE_INACTIVE = "spriteInact";
	const sf::String COMP_CLICK = "clickComp";

	int playerID;
	sf::CircleShape* shape;

	SpriteComponent* spriteComp;
	ClickableComponent* clickComp;

public:
	Pawn();
	Pawn(int playerID);
	~Pawn();

	int Pawn::GetPlayerID();
	void Pawn::SetPlayerID(int value);
	void setPosition(int x, int y);

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;
};

