#include "Board.h")
#include <iostream>


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

void Board::switchCases(int index1, int index2)
{
	Case* tmp = _cases[index1];

	int x1 = tmp->getPosition().x;
	int y1 = tmp->getPosition().y;
	int x2 = _cases[index2]->getPosition().x;
	int y2 = _cases[index2]->getPosition().y;

	_cases[index1] = _cases[index2];
	_cases[index2] = tmp;

	_cases[index1]->disableClick();
	_cases[index2]->disableClick();

	_cases[index1]->setPosition(x1, y1);
	_cases[index2]->setPosition(x2, y2);

	_cases[index1]->enableClick();
	_cases[index2]->enableClick();
}
