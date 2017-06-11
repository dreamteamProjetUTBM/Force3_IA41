#include "Board.h"



Board::Board()
{
	_size = 9;
	_pawns_player_1 = 0;
	_pawns_player_2 = 0;

	_cases[0] = new Case("Case 0", "ressources/case.png",100,100);
	_cases[1] = new Case("Case 1", "ressources/case.png",200,100);
	_cases[2] = new Case("Case 2", "ressources/case.png",300,100);
	_cases[3] = new Case("Case 3", "ressources/case.png",100,200);
	_cases[4] = new Case("Case 4", "ressources/empty.png",200,200);
	_cases[5] = new Case("Case 5", "ressources/case.png",300,200);
	_cases[6] = new Case("Case 6", "ressources/case.png",100,300);
	_cases[7] = new Case("Case 7", "ressources/case.png",200,300);
	_cases[8] = new Case("Case 8", "ressources/case.png",300,300);

	_cases[2]->SetPawn(new Pawn(2,"ressources/pawn_j2.png"));

}


Board::~Board()
{
	
}

int Board::GetSize() {
	return _size;
}
void Board::SetSize(int value) {
	_size = value;
}


int Board::GetPawnsPlayer1() {
	return _pawns_player_1;
}
void Board::SetPawnsPlayer1(int value) {
	_pawns_player_1 = value;
}

int Board::GetPawnsPlayer2() {
	return _pawns_player_2;
}
void Board::SetPawnsPlayer2(int value) {
	_pawns_player_2 = value;
}

Case** Board::GetCases() {
	return _cases;
}
void Board::SetCases(Case* value[9]) {
	for(int i=0;i<9;i++)
	{
		_cases[i] = value[i];
	}
}