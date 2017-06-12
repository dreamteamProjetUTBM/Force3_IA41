#include "Game.h"



Game::Game()
{
	SetScoreJ1(0);
	SetScoreJ2(0);
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

GameScene * Game::getGameScene() const
{
	return _gameScene;
}

