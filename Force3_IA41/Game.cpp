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
	taquin_double.insert(std::pair<int, std::vector<int>>(3, std::vector<int> {5}));
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

void Game::setOldPositionByPawn(Pawn * value)
{
	std::vector<Case*> cases = getGameScene()->getBoard()->GetCases();
	for (int i = 0; i<9; i++)
	{
		if (cases[i]->GetPawn() == value)
			old_position = i;
	}
}

void Game::setNewPositionByPawn(Pawn * value)
{
	std::vector<Case*> cases = getGameScene()->getBoard()->GetCases();
	for (int i = 0; i<9; i++)
	{
		if (cases[i]->GetPawn() == value)
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

int Game::getMiddleIndexOfTaquin2()
{
	if ((old_position == 0 && new_posistion == 6) || (old_position == 6 && new_posistion == 0))
		return 3;
	if ((old_position == 0 && new_posistion == 2) || (old_position == 2 && new_posistion == 0))
		return 1;
	if ((old_position == 1 && new_posistion == 7) || (old_position == 7 && new_posistion == 1))
		return 4;
	if ((old_position == 2 && new_posistion == 8) || (old_position == 8 && new_posistion == 2))
		return 5;
	if ((old_position == 3 && new_posistion == 5) || (old_position == 5 && new_posistion == 3))
		return 4;
	if ((old_position == 6 && new_posistion == 8) || (old_position == 8 && new_posistion == 6))
		return 7;
}

bool Game::joue(int coup)
{
	if (coup == 1) //ajout pion
	{
		Case* target = getGameScene()->getBoard()->GetCases()[old_position];
		if (target->GetPawn()->GetPlayerID() == 0) //&& NbPions du joueur < 3) //On peut ajouter le pion
		{
			//Joueur 1 sera toujours l'humain
			target->GetPawn()->SetPawn(1, target->getPosition().x, target->getPosition().y);

		}
	}
	else if (coup == 3) //deplacement case ou pion
	{
		if (old_position == new_posistion)
		{
			std::cout << "Erreur : tu as choisi deux fois la meme position" << std::endl;
			setCoupEnCours(false);
			return false;
		}

		std::vector<Case*> cases = getGameScene()->getBoard()->GetCases();

		if ((cases[old_position]->GetPawn()->GetPlayerID() > 0 && cases[new_posistion]->GetPawn()->GetPlayerID() == 0 && !cases[new_posistion]->isEmpty()) ||
			(cases[new_posistion]->GetPawn()->GetPlayerID() > 0 && cases[old_position]->GetPawn()->GetPlayerID() == 0 && !cases[old_position]->isEmpty()))
		{
			std::cout << "Deplacement Pion" << std::endl;
			//deplacement du pion
			std::vector<int> posibilities = getCasesIndex_AdjacentAndDiagonal(old_position);
			bool is_correct = false;
			for each (int posibility in posibilities)
			{
				if (posibility == new_posistion)
					is_correct = true;
			}

			if (is_correct)
				getGameScene()->getBoard()->switchCases(old_position, new_posistion);
		}

		else {
			std::cout << "Deplacement Case" << std::endl;

			if (!cases[old_position]->isEmpty() && !cases[new_posistion]->isEmpty()) {
				std::cout << "Erreur : deplacement incorrect" << std::endl;
				setCoupEnCours(false);
				return false;
			}

			bool est_taquin_simple = false, est_taquin_double = false;

			std::vector<int> taquin_old_position = taquin_simple.at(old_position);
			for each (int index in taquin_old_position)
			{
				if (index == new_posistion)
					est_taquin_simple = true;
			}

			if (old_position != 4 && new_posistion != 4) {
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
			if (est_taquin_double) {
				int middle = getMiddleIndexOfTaquin2();
				getGameScene()->getBoard()->switchCases(old_position, new_posistion);
				getGameScene()->getBoard()->switchCases(new_posistion, middle);
			}
			//std::cout << "erreur" << std::endl;
		}
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
