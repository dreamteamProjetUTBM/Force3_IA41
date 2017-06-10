#pragma once
#include "Scene.h"
#include "Board.h"

/*
	Classe GameScene

	Scene qui représente la phase de jeu
*/

#define SCENE_GAME "gameScene"

class GameScene : public Scene
{
private:
	Board* board;

public:
	GameScene();
	~GameScene();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;
};

