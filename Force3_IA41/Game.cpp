#include "Game.h"
#include <iostream>

Game Game::m_instance = Game();	

Game & Game::Instance()
{
	return m_instance;
}

Game::Game()
{
	

	setScoreJ1(0);
	setScoreJ2(0);

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


int Game::getScoreJ1() const
{
	return _score_J1;
}
void Game::setScoreJ1(int value) {
	_score_J1 = value;
}

int Game::getScoreJ2() const
{
	return _score_J2;
}
void Game::setScoreJ2(int value) {
	_score_J2 = value;
}

int Game::getPlayersTurn() const
{
	return whosTurnIs;
}

void Game::setPlayersTurn(int value)
{
	whosTurnIs = value;
}

bool Game::getCoupEnCours()
{
	return coup_en_cours;
}

void Game::setCoupEnCours(bool value)
{
	coup_en_cours = value;
}

int Game::getJ1NumberPawn()
{
	return gameScene->getBoard()->GetPawnsPlayer1();
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
	return gameScene;
}

void Game::setGameScene(GameScene* value) {
	gameScene = value;
}

int Game::getMiddleIndexOfTaquin2(int _old_position, int _new_position)
{
	if ((_old_position == 0 && _new_position == 6) || (_old_position == 6 && _new_position == 0))
		return 3;
	if ((_old_position == 0 && _new_position == 2) || (_old_position == 2 && _new_position == 0))
		return 1;
	if ((_old_position == 1 && _new_position == 7) || (_old_position == 7 && _new_position == 1))
		return 4;
	if ((_old_position == 2 && _new_position == 8) || (_old_position == 8 && _new_position == 2))
		return 5;
	if ((_old_position == 3 && _new_position == 5) || (_old_position == 5 && _new_position == 3))
		return 4;
	if ((_old_position == 6 && _new_position == 8) || (_old_position == 8 && _new_position == 6))
		return 7;
}

bool Game::joue(int coup)
{
	bool est_taquin_simple = false, est_taquin_double = false;
	

	std::vector<Case*> cases = getGameScene()->getBoard()->GetCases();
	std::vector<int> taquin_old_position = taquin_simple.at(old_position);
	
	if (coup == 1) {
		if (old_position == new_posistion)
		{
			std::cout << "Erreur : tu as choisi deux fois la meme position" << std::endl;
			setCoupEnCours(false);
			return false;
		}

		if ((cases[old_position]->GetPawn()->GetPlayerID() > 0 && cases[new_posistion]->GetPawn()->GetPlayerID() == 0 && !cases[new_posistion]->isEmpty()) ||
			(cases[new_posistion]->GetPawn()->GetPlayerID() > 0 && cases[old_position]->GetPawn()->GetPlayerID() == 0 && !cases[old_position]->isEmpty()))
			coup = 1;
		else {
			if (!cases[old_position]->isEmpty() && !cases[new_posistion]->isEmpty()) {
				std::cout << "Erreur : deplacement incorrect" << std::endl;
				setCoupEnCours(false);
				return false;
			}

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


			if (est_taquin_simple)
				coup = 2;
			else if (est_taquin_double)
				coup = 3;
		}

	}

	std::vector<int> coupPlayer;
	if (coup == 0) 
		coupPlayer = { -1,old_position, coup };
	else 
		coupPlayer = { old_position, new_posistion, coup };


	if (!ppsc->isPossible(gameScene->getBoard()->getPrologBoard(), coupPlayer)) {
		std::cout << "Coup impossible" << std::endl;
		return false;
	}


	if (coup == 0) //ajout pion
	{
		Case* target = getGameScene()->getBoard()->GetCases()[old_position];
		if (target->GetPawn()->GetPlayerID() == 0) //&& NbPions du joueur < 3) //On peut ajouter le pion
		{
			//Joueur 1 sera toujours l'humain
			target->GetPawn()->SetPawn(1, target->getPosition().x, target->getPosition().y);
		}
	}
	else if (coup == 1) //deplacement case ou pion
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
		if (est_taquin_simple) {
			getGameScene()->getBoard()->switchCases(old_position, new_posistion);
		}
		if (est_taquin_double) {
			int middle = getMiddleIndexOfTaquin2(old_position, new_posistion);
			getGameScene()->getBoard()->switchCases(old_position, new_posistion);
			getGameScene()->getBoard()->switchCases(new_posistion, middle);
		}
	}
	

	bool victory = iapsc->win(gameScene->getBoard()->getPrologBoard(), 1);
	if (victory)
		std::cout << "Joueur 1 gagne" << std::endl;
	else
		whosTurnIs = 2;


	launchGame();
	return false;
}

bool Game::joueIA(int _old_position, int _new_position, int _coup)
{
	Case* first_case;

	switch (_coup) {
	case 0: //ajout pion
		first_case = getGameScene()->getBoard()->GetCases()[_new_position];
		first_case->GetPawn()->SetPawn(2, first_case->getPosition().x, first_case->getPosition().y);
		break;
	case 1: //deplacement d'un pion
		getGameScene()->getBoard()->switchCases(_old_position, _new_position);
		break;
	case 2: //deplacement d'une case
		getGameScene()->getBoard()->switchCases(_old_position, _new_position);
		break;
	case 3:
		int middle = getMiddleIndexOfTaquin2(old_position, new_posistion);
		getGameScene()->getBoard()->switchCases(old_position, new_posistion);
		getGameScene()->getBoard()->switchCases(new_posistion, middle);
		break;
	}
	return true;
}

void Game::launchGame() {

	bool victory = false;

	//while (!victory) {

		//Player 1 joue
		if (whosTurnIs == 2) {

			std::vector<int> bo = gameScene->getBoard()->getPrologBoard();
			std::vector<int> coupIA = iapsc->bestCombination(bo);
			joueIA(coupIA[0], coupIA[1], coupIA[2]);

			bool victory = iapsc->win(gameScene->getBoard()->getPrologBoard(), 2);
			if (victory)
				std::cout << "Joueur 2 gagne" << std::endl;
			else 
				whosTurnIs = 1;
		}


	//}

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
