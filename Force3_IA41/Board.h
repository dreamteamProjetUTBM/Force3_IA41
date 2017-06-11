#pragma once

#include "Case.h"

/* CONSTANTES */
const sf::String CASE_0 = "Case 0";
const sf::String CASE_1 = "Case 1";
const sf::String CASE_2 = "Case 2";
const sf::String CASE_3 = "Case 3";
const sf::String CASE_4 = "Case 4";
const sf::String CASE_5 = "Case 5";
const sf::String CASE_6 = "Case 6";
const sf::String CASE_7 = "Case 7";
const sf::String CASE_8 = "Case 8";

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

	Case* _cases[9];

public:
	Board();
	~Board();

	int Board::GetSize();
	void Board::SetSize(int value);

	int Board::GetPawnsPlayer1();
	void Board::SetPawnsPlayer1(int value);

	int Board::GetPawnsPlayer2();
	void Board::SetPawnsPlayer2(int value);

	Case** Board::GetCases();
	void Board::SetCases(Case* value[9]);
};

