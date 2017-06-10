#include "GameScene.h"



GameScene::GameScene() : Scene(SCENE_GAME)
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
	Pawn* test = new Pawn(1, "ressources/pawn_j1.png");

	_cases[1]->SetPawn(test);

}

void GameScene::update(Display * _disp, sf::Event & _event)
{
	Scene::update(_disp, _event);
}

void GameScene::draw(Display * _disp)
{
	Scene::draw(_disp);
}
