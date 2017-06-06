#include "Case.h"



Case::Case()
{
}


Case::~Case()
{
}


Pawn Case::GetPawn() {
	return _pawn;
}

void Case::SetPawn(Pawn value) {
	_pawn = value;
}