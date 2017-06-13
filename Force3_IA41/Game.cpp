#include "Game.h"
#include <iostream>

Game Game::m_instance = Game();	

Game & Game::Instance()
{
	return m_instance;
}

Game::Game()
{
	SetScoreJ1(0);
	SetScoreJ2(0);

	taquin_simple.insert(std::pair<int, std::vector<int>>(0, std::vector<int> {1, 3}));
	taquin_simple.insert(std::pair<int, std::vector<int>>(1, std::vector<int> {0, 2, 4}));
	taquin_simple.insert(std::pair<int, std::vector<int>>(2, std::vector<int> {1, 5}));
	taquin_simple.insert(std::pair<int, std::vector<int>>(3, std::vector<int> {0, 4, 6}));
	taquin_simple.insert(std::pair<int, std::vector<int>>(4, std::vector<int> {1, 3, 5, 7}));
	taquin_simple.insert(std::pair<int, std::vector<int>>(5, std::vector<int> {2, 4, 8}));
	taquin_simple.insert(std::pair<int, std::vector<int>>(6, std::vector<int> {3, 7}));
	taquin_simple.insert(std::pair<int, std::vector<int>>(7, std::vector<int> {4, 6, 8}));
	taquin_simple.insert(std::pair<int, std::vector<int>>(8, std::vector<int> {5, 7}));

	taquin_double.insert(std::pair<int, std::vector<int>>(0, std::vector<int> {2, 6}));
	taquin_double.insert(std::pair<int, std::vector<int>>(1, std::vector<int> {7}));
	taquin_double.insert(std::pair<int, std::vector<int>>(2, std::vector<int> {0, 8}));
	taquin_double.insert(std::pair<int, std::vector<int>>(3, std::vector<int> {0, 4, 6}));
	taquin_double.insert(std::pair<int, std::vector<int>>(5, std::vector<int> {3}));
	taquin_double.insert(std::pair<int, std::vector<int>>(6, std::vector<int> {0, 8}));
	taquin_double.insert(std::pair<int, std::vector<int>>(7, std::vector<int> {1}));
	taquin_double.insert(std::pair<int, std::vector<int>>(8, std::vector<int> {2, 6}));
}


Game::~Game()
{
}


int Game::GetScoreJ1() const
{
	return _score_J1;
}
void Game::SetScoreJ1(int value) {
	_score_J1 = value;
}

int Game::GetScoreJ2() const
{
	return _score_J2;
}
void Game::SetScoreJ2(int value) {
	_score_J2 = value;
}

int Game::getPlayersTurn() const
{
	return _whosTurnIs;
}

void Game::setPlayersTurn(int value)
{
	_whosTurnIs = value;
}

bool Game::getCoupEnCours()
{
	return coup_en_cours;
}

void Game::setCoupEnCours(bool value)
{
	coup_en_cours = value;
}

void Game::setOldPosition(Case* value)
{
	std::vector<Case*> cases = getGameScene()->getBoard()->GetCases();

	for (int i = 0; i<9; i++)
	{
		if (cases[i] == value)
			old_position = i;
	}
}

void Game::setNewPosition(Case* value)
{
	std::vector<Case*> cases = getGameScene()->getBoard()->GetCases();
	for (int i = 0; i<9; i++)
	{
		if (cases[i] == value)
			new_posistion = i;
	}
}


GameScene * Game::getGameScene() const
{
	return _gameScene;
}

void Game::setGameScene(GameScene* value) {
	_gameScene = value;
}

bool Game::verification_deplacement_cases()
{
	Board* board = getGameScene()->getBoard();
	return isAdjaccent(board->GetCases());
}

bool Game::joue(int coup)
{
	if (coup == 1) //ajout pion
	{
		
	}
	else if (coup == 2) //deplacement pion
	{
		
	}
	else if (coup == 3) //deplacement case
	{
		if (old_position == new_posistion)
		{
			std::cout << "Erreur : tu as choisi deux fois la meme position" << std::endl;
			setCoupEnCours(false);
			return false;
		}

		bool rep = verification_deplacement_cases();
		bool est_taquin_simple = false, est_taquin_double = false;

		std::vector<int> taquin_old_position = taquin_simple.at(old_position);

		for each (int index in taquin_old_position)
		{
			if (index == new_posistion)
				est_taquin_simple = true;
		}

		if (old_position != 4) {
			taquin_old_position = taquin_double.at(old_position);

			for each (int index in taquin_old_position)
			{
				if (index == new_posistion)
					est_taquin_double = true;
			}
		}
		if (est_taquin_simple) {
			getGameScene()->getBoard()->switchCases(old_position, new_posistion);
		}
		//setCoupEnCours(false);
		std::cout << "erreur" << std::endl;
	}
	return false;
}



std::vector<int> Game::getCasesIndex_AdjacentAndDiagonal(int index)
{
	std::vector<int> vec(8);
	switch (index) {
	case 0:
		vec.push_back(1);
		vec.push_back(3);
		vec.push_back(4);
		break;
	case 1:
		vec.push_back(0);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		break;
	case 2:
		vec.push_back(1);
		vec.push_back(4);
		vec.push_back(5);
		break;
	case 3:
		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(4);
		vec.push_back(6);
		vec.push_back(7);
		break;
	case 4:
		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(5);
		vec.push_back(6);
		vec.push_back(7);
		vec.push_back(8);
		break;
	case 5:
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(4);
		vec.push_back(7);
		vec.push_back(8);
		break;
	case 6:
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(7);
		break;
	case 7:
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		vec.push_back(6);
		vec.push_back(8);
		break;
	case 8:
		vec.push_back(4);
		vec.push_back(5);
		vec.push_back(7);
		break;
	}
	return vec;
}

std::vector<int> Game::getCasesIndex_Adjacent(int index)
{
	std::vector<int> vec(8);
	switch (index) {
	case 0:
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(6);
		break;
	case 1:
		vec.push_back(0);
		vec.push_back(2);
		vec.push_back(4);
		vec.push_back(7);
		break;
	case 2:
		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(5);
		vec.push_back(6);
		break;
	case 3:
		vec.push_back(0);
		vec.push_back(4);
		vec.push_back(5);
		vec.push_back(6);
		break;
	case 4:
		vec.push_back(1);
		vec.push_back(3);
		vec.push_back(5);
		vec.push_back(7);
		break;
	case 5:
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(8);
		break;
	case 6:
		vec.push_back(0);
		vec.push_back(3);
		vec.push_back(7);
		vec.push_back(8);
		break;
	case 7:
		vec.push_back(1);
		vec.push_back(4);
		vec.push_back(6);
		vec.push_back(8);
		break;
	case 8:
		vec.push_back(2);
		vec.push_back(5);
		vec.push_back(6);
		vec.push_back(7);
		break;
	}
	return vec;
}

bool Game::isAdjaccentOrDiagonale(std::vector<Case*> cases)
{
	/*
	for (int i = 0; i < 9; i++) {
	if (cases[i]->getName() == old_position->getName()) {
	std::vector<int> cases_adacentes = getCasesIndex_AdjacentAndDiagonal(i);

	for each (int j in cases_adacentes)
	{
	if (cases[j]->getName() == new_posistion->getName())
	return true;
	}
	}
	}*/
	return false;
}

bool Game::isAdjaccent(std::vector<Case*> cases)
{/*
 for (int i = 0; i < 9; i++) {
 if (cases[i]->getName() == old_position->getName()) {
 std::vector<int> cases_adacentes = getCasesIndex_Adjacent(i);

 for each (int j in cases_adacentes)
 {
 if (cases[j]->getName() == new_posistion->getName())
 return true;
 }
 }
 }*/
	return false;
}

