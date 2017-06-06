#include "Pawn.h"



Pawn::Pawn()
{
}

Pawn::Pawn(int playerID) {
	SetPlayerID(playerID);
}

Pawn::~Pawn()
{
}

int Pawn::GetPlayerID() {
	return playerID;
}

void Pawn::SetPlayerID(int value) {
	playerID = value;
}