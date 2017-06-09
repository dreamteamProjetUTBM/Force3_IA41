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
	addGameObject(button);
}

void MenuScene::update(Display * _disp)
{
	Scene::update(_disp);
}

void MenuScene::draw(Display * _disp)
{
	Scene::draw(_disp);
}
