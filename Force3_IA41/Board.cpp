#include "Board.h")



Board::Board()
{
	_size = 9;
	_pawns_player_1 = 0;
	_pawns_player_2 = 0;

	_cases = std::vector<Case*>(9);
	_cases[0] = new Case(CASE_0, "ressources/case.png", 50, 50,false);
	_cases[1] = new Case(CASE_1, "ressources/case.png", 178, 50, false);
	_cases[2] = new Case(CASE_2, "ressources/case.png", 306, 50, false);
	_cases[3] = new Case(CASE_3, "ressources/case.png", 50, 178, false);
	_cases[4] = new Case(CASE_4, "ressources/empty.png", 178, 178,true);
	_cases[5] = new Case(CASE_5, "ressources/case.png", 306, 178, false);
	_cases[6] = new Case(CASE_6, "ressources/case.png", 50, 306, false);
	_cases[7] = new Case(CASE_7, "ressources/case.png", 178, 306, false);
	_cases[8] = new Case(CASE_8, "ressources/case.png", 306, 306, false);

	//_cases[2]->SetPawn(new Pawn(2,_cases[2]->getPosition().x, _cases[2]->getPosition().y));

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

std::vector<Case*> Board::GetCases() {
	return _cases;
}
void Board::SetCases(std::vector<Case*> value) {
	_cases = value;
}