#include "MenuScene.h"

MenuScene::MenuScene() : Scene(SCENE_MENU)
{
	shape.setPosition(100, 100);
	shape.setSize(sf::Vector2f(100, 50));
	shape.setFillColor(sf::Color::White);
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
}

void MenuScene::update(Display * _disp)
{
}

void MenuScene::draw(Display * _disp)
{
}
