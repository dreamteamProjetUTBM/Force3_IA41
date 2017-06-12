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
	_disp->setClearColor(254, 242, 216);

	/* Bonton pour lancer la partie */
	playButton = new Button(BTN_PLAY, "ressources/btn_play_normal.png", "ressources/btn_play_hover.png", "ressources/btn_play_pressed.png",
		[](SpriteComponent* sc) {},
		[](SpriteComponent* sc) {},
		[_disp](SpriteComponent* sc) { _disp->switchScene(SCENE_GAME); });

	playButton->setPosition(_disp->getWindow().getSize().x / 2 - 200 / 2, 250);
	addGameObject(playButton);

	/* Bouton pour quitter le jeu */
	quitButton = new Button(BTN_QUIT, "ressources/btn_quit_normal.png", "ressources/btn_quit_hover.png", "ressources/btn_quit_pressed.png",
		[](SpriteComponent* sc) {},
		[](SpriteComponent* sc) {},
		[_disp](SpriteComponent* sc) { _disp->close(); });
	quitButton->setPosition(_disp->getWindow().getSize().x / 2 - 200 / 2, 320);
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
