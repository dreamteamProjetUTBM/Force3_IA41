/*
	Projet Force3 IA41
*/
#include <iostream>
#include <SWI-cpp.h>

#include "MenuScene.h"
#include "GameScene.h"
#include "Game.h"

int main(int argc, char* argv[]) 
{
	/* Permet de mettre en place l'environnement !!! Obligatoire sinon �a ne
	 fonctionne pas du tout !!!*/
	_putenv("SWI_HOME_DIR=C:\\Program Files (x86)\\swipl\\");

	Scene* menu = new MenuScene();
	GameScene* game = new GameScene(argv[0]);
	Game::Instance().setGameScene(game);

	Display* disp = new Display(854, 480, "Force 3");
	disp->addScene(menu);
	disp->addScene(game);

	disp->switchScene(SCENE_MENU);
	disp->start(true);

	delete disp;
}