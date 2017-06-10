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
	int playerID;

	SpriteComponent* spriteComp;
	ClickableComponent* clickComp;

public:
	Pawn();
	Pawn(int playerID);
	~Pawn();

	int Pawn::GetPlayerID();
	void Pawn::SetPlayerID(int value);
};

