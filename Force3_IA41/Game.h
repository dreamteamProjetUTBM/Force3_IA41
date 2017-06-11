#pragma once
#include "GameScene.h"
/*
	Classe Game

	Permet de g�rer les scores, d'effectuer des v�rification sur 
	le respect des r�gles du jeu en appellant des pr�dicats prolog.
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

	int Game::GetScoreJ1() const;
	void Game::SetScoreJ1(int value);

	int Game::GetScoreJ2() const;
	void Game::SetScoreJ2(int value);

	int Game::getPlayersTurn() const;
	void Game::setPlayersTurn(int value);

	GameScene* getGameScene() const;

	static int Play();


};

