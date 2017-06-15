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

	std::vector<Case*> _cases;

public:
	Board();
	~Board();

	int GetSize() const;
	void SetSize(int value);

	int GetPawnsPlayer1() const;
	void SetPawnsPlayer1(int value);

	int GetPawnsPlayer2() const;
	void SetPawnsPlayer2(int value);

	std::vector<Case*> GetCases() const;
	void SetCases(std::vector<Case*> value);

	void switchCases(int index1, int index2);

	std::vector<int> getPrologBoard();
};

