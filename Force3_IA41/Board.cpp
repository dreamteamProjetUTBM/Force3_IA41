#include "Board.h"



Board::Board()
{
	_size = 9;
	_pawns_player_1 = 0;
	_pawns_player_2 = 0;

}


Board::~Board()
{
	_cases.clear();
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

std::list<Case> Board::GetCases() {
	return _cases;
}
void Board::SetCases(std::list<Case> value) {
	_cases = value;
}