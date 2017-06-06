#pragma once
#include "Pawn.h"

/*
	Classe Case

	GameObject qui repr�sente une case sur le plateau
*/
class Case
{
private:
	Pawn _pawn;


public:
	Case();
	~Case();

	Pawn Case::GetPawn();
	void Case::SetPawn(Pawn value);
};

