#pragma once
#include "GameScene.h"
#include "Board.h"
/*
	Classe Game

	Permet de g�rer les scores, d'effectuer des v�rification sur 
	le respect des r�gles du jeu en appellant des pr�dicats prolog.
*/
class Game
{
private:
	static Game m_instance;

	int _score_J1;
	int _score_J2;
	bool coup_en_cours = false;

	int _whosTurnIs;
	GameScene* _gameScene;

	int old_position;
	int new_posistion;

	std::map<int, std::vector<int>> taquin_simple;
	std::map<int, std::vector<int>> taquin_double;


	std::vector<int> getCasesIndex_AdjacentAndDiagonal(int index);
	std::vector<int> getCasesIndex_Adjacent(int index);
	bool isAdjaccentOrDiagonale(std::vector<Case*> cases);
	bool isAdjaccent(std::vector<Case*> cases);


public:
	static Game& Instance();

	Game();
	~Game();

	int Game::GetScoreJ1() const;
	void Game::SetScoreJ1(int value);

	int Game::GetScoreJ2() const;
	void Game::SetScoreJ2(int value);

	int Game::getPlayersTurn() const;
	void Game::setPlayersTurn(int value);

	bool getCoupEnCours();
	void setCoupEnCours(bool value);

	void setOldPosition(Case* value);
	void setNewPosition(Case* value);

	GameScene* getGameScene() const;

};

