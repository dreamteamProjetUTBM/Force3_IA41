#include "MenuScene.h"
#include "GameScene.h"
#include <iostream>

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
	button = new Button("Jouer !", 
		[_disp](SpriteComponent* sc) { _disp->switchScene(SCENE_GAME); },
		[](SpriteComponent* sc) { std::cout << "Right pressed" << std::endl; },
		[](SpriteComponent* sc) { std::cout << "released" << std::endl; });

	button->setPosition(250, 250);
	addGameObject(button);
}

void MenuScene::update(Display * _disp, sf::Event& _event)
{
	Scene::update(_disp, _event);
}

void MenuScene::draw(Display * _disp)
{
	Scene::draw(_disp);
}
