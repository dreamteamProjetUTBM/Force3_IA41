#include "Game.h"



Game::Game()
{
	SetScoreJ1(0);
	SetScoreJ2(0);
}


Game::~Game()
{
}


int Game::GetScoreJ1() {
	return _score_J1;
}
void Game::SetScoreJ1(int value) {
	_score_J1 = value;
}

int Game::GetScoreJ2() {
	return _score_J2;
}
void Game::SetScoreJ2(int value) {
	_score_J2 = value;
}

int Game::getPlayersTurn()
{
	return _whosTurnIs;
}

void Game::setPlayersTurn(int value)
{
	_whosTurnIs = value;
}

GameScene * Game::getGameScene()
{
	return _gameScene;
}

int Game::Play()
{
	bool win= false;

	while (!win) {

	}

	return 1; //J1 gagne
}
