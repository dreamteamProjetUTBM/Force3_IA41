/*
	Projet Force3 IA41
*/
#include <iostream>
#include <SWI-cpp.h>

#include "MenuScene.h"
#include "GameScene.h"

int main(int argc, char* argv[]) 
{
	/* Permet de mettre en place l'environnement !!! Obligatoire sinon ça ne
	 fonctionne pas du tout !!!*/
	//ATTENTION : Thomas j'ai changé le "pl" en "swipl"
	_putenv("SWI_HOME_DIR=C:\\Program Files (x86)\\swipl\\");

	Scene* menu = new MenuScene();
	Scene* game = new GameScene(argv[0]);


	Display* disp = new Display(854, 480, "Force 3");
	disp->addScene(menu);
	disp->addScene(game);

	disp->switchScene(SCENE_MENU);
	//disp->switchScene(SCENE_GAME);
	disp->start(true);

	delete disp;
}