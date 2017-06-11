#pragma once
#include "GameScene.h"
/*
	Classe Game

	Permet de gérer les scores, d'effectuer des vérification sur 
	le respect des règles du jeu en appellant des prédicats prolog.
*/
class Game
{
private:
	int _score_J1;
	int _score_J2;
	int _whosTurnIs;
	GameScene* _gameScene;

public:
	Game();
	~Game();

	int Game::GetScoreJ1();
	void Game::SetScoreJ1(int value);

	int Game::GetScoreJ2();
	void Game::SetScoreJ2(int value);

	int Game::getPlayersTurn();
	void Game::setPlayersTurn(int value);

	GameScene* getGameScene();

	int Play();


};

