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
	/* On met le fond de la fen�tre en blanc */
	_disp->setClearColor(254, 242, 216);

	/* Bonton pour lancer la partie */
	playButton = new Button(BTN_PLAY, "ressources/btn_play.png", "ressources/btn_play.png", "ressources/btn_play.png",
		[](SpriteComponent* sc) {},
		[](SpriteComponent* sc) {},
		[_disp](SpriteComponent* sc) { _disp->switchScene(SCENE_GAME); });

	playButton->setPosition(250, 250);
	addGameObject(playButton);

	/* Bouton pour quitter le jeu */
	quitButton = new Button(BTN_QUIT, "ressources/btn_play.png", "ressources/btn_play.png", "ressources/btn_play.png",
		[](SpriteComponent* sc) {},
		[](SpriteComponent* sc) {},
		[_disp](SpriteComponent* sc) { _disp->close(); });
	addGameObject(quitButton);
}

void MenuScene::update(Display * _disp, sf::Event& _event)
{
	Scene::update(_disp, _event);
}

void MenuScene::draw(Display * _disp)
{
	Scene::draw(_disp);
}
