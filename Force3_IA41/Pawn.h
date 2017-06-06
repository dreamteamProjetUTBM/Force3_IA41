#pragma once

/*
	Classe Pawn

	GameObject qui repr�sente un pion de jeu
*/
class Pawn
{
private:
	int playerID;

public:
	Pawn();
	Pawn(int playerID);
	~Pawn();

	int Pawn::GetPlayerID();
	void Pawn::SetPlayerID(int value);
};

