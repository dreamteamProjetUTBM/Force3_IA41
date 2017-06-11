#include "GameScene.h"

GameScene::GameScene(char* arg0) : Scene(SCENE_GAME)
{
}

GameScene::~GameScene()
{
}

void GameScene::init(Display * _disp)
{

	_disp->setClearColor(172, 172, 172);
	board = new Board();

	Case** _cases = board->GetCases();

	for (int i = 0; i < 9; i++) {
		addGameObject(_cases[i]);
		addGameObject(_cases[i]->GetPawn());
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
