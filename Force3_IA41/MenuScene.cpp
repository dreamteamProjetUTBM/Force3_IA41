#include "MenuScene.h"

MenuScene::MenuScene() : Scene(SCENE_MENU)
{
}

MenuScene::~MenuScene()
{
	for (auto gameObjet : gameObjects)
	{
		delete gameObjet;
	}
	gameObjects.clear();
}

void MenuScene::init(Display * _disp)
{
	button = new Button("Jouer !");
}

void MenuScene::update(Display * _disp)
{
}

void MenuScene::draw(Display * _disp)
{
}
