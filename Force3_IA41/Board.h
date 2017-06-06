#pragma once
#include <list>
#include "Case.h"
/*
	Classe Board

	GameObject qui représente le plateau de jeu
*/
class Board
{
private:
	int _size;
	int _pawns_player_1;
	int _pawns_player_2;

	std::list<Case> _cases;

public:
	Board();
	~Board();

	int Board::GetSize();
	void Board::SetSize(int value);

	int Board::GetPawnsPlayer1();
	void Board::SetPawnsPlayer1(int value);

	int Board::GetPawnsPlayer2();
	void Board::SetPawnsPlayer2(int value);

	std::list<Case> Board::GetCases();
	void Board::SetCases(std::list<Case> value);


	
};

