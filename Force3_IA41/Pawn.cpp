#include "Pawn.h"



Pawn::Pawn() : GameObject("null")
{
}

Pawn::Pawn(int playerID) : GameObject(""+playerID){
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