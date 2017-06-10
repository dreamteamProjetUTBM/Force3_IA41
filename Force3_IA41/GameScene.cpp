#include "GameScene.h"



GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::init(Display * _disp)
{
	board = new Board();

	Case** _cases = board->GetCases();

	for (int i = 0; i < 9; i++) {
		addGameObject(_cases[i]);
	}
}

void GameScene::update(Display * _disp, sf::Event & _event)
{
	Scene::update(_disp, _event);
}

void GameScene::draw(Display * _disp)
{
	Scene::draw(_disp);
}
