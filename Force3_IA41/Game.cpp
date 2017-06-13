#include "Game.h"


Game Game::m_instance = Game();	

Game & Game::Instance()
{
	return m_instance;
	// TODO: insérer une instruction return ici
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

