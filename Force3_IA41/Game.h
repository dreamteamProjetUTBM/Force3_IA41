#pragma once
#include "GameScene.h"
#include "Board.h"
#include "PlayerPrologScriptComponent.h"
#include "IAPrologScriptComponent.h"
/*
	Classe Game

	Permet de gérer les scores, d'effectuer des vérification sur 
	le respect des règles du jeu en appellant des prédicats prolog.
*/
class Game
{
private:
	static Game m_instance;

	

	int _score_J1;
	int _score_J2;
	bool coup_en_cours;

	
	int whosTurnIs;
	GameScene* gameScene;

	int old_position;
	int new_posistion;

	std::map<int, std::vector<int>> taquin_simple;
	std::map<int, std::vector<int>> taquin_double;


	std::vector<int> getCasesIndex_AdjacentAndDiagonal(int index);
	std::vector<int> getCasesIndex_Adjacent(int index);
	int getMiddleIndexOfTaquin2(int _old_position, int _new_position);

public:
	PlayerPrologScriptComponent* ppsc;
	IAPrologScriptComponent* iapsc;

	static Game& Instance();

	Game();
	~Game();

	int getScoreJ1() const;
	void setScoreJ1(int value);

	int getScoreJ2() const;
	void setScoreJ2(int value);

	int getPlayersTurn() const;
	void setPlayersTurn(int value);

	bool getCoupEnCours();
	void setCoupEnCours(bool value);

	int getJ1NumberPawn();

	void setOldPosition(Case* value);
	void setNewPosition(Case* value);
	void setOldPositionByPawn(Pawn* value);
	void setNewPositionByPawn(Pawn* value);

	void setGameScene(GameScene* value);
	GameScene* getGameScene() const;
	bool joue(int coup);
	bool joueIA(int _old_position, int _new_position, int _coup);

	void launchGame();


};

