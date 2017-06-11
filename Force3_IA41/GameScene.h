#pragma once
#include "Scene.h"
#include "Board.h"

#define SCENE_GAME "gameScene"

/*
	Classe GameScene

	Scene qui représente la phase de jeu
*/
class GameScene : public Scene
{
private:
	Board* board;

public:
	GameScene(char* arg0);
	~GameScene();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;
};

