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
	/* On met le fond de la fenêtre en blanc */
	_disp->setClearColor(255, 255, 255);

	/* Bonton pour lancer la partie */
	playButton = new Button("Jouer", 
		[](SpriteComponent* sc) {},
		[](SpriteComponent* sc) {},
		[_disp](SpriteComponent* sc) { _disp->switchScene(SCENE_GAME); });

	playButton->setPosition(250, 250);
	addGameObject(playButton);

	/* Bouton pour quitter le jeu */
	quitButton = new Button("Quitter",
		[](SpriteComponent* sc) {},
		[](SpriteComponent* sc) {},
		[_disp](SpriteComponent* sc) { _disp->close(); });
}

void MenuScene::update(Display * _disp, sf::Event& _event)
{
	Scene::update(_disp, _event);
}

void MenuScene::draw(Display * _disp)
{
	Scene::draw(_disp);
}
