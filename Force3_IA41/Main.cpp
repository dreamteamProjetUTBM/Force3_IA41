/*
	Projet Force3 IA41
*/
#include <iostream>
#include <SWI-cpp.h>

#include "MenuScene.h"

int main(int argc, char* argv[]) 
{
	/* Permet de mettre en place l'environnement !!! Obligatoire sinon ça ne
	 fonctionne pas du tout !!!*/
	//ATTENTION : Thomas j'ai changé le "pl" en "swipl"
	_putenv("SWI_HOME_DIR=C:\\Program Files (x86)\\swipl\\");

	Scene* menu = new MenuScene();

	Display* disp = new Display(854, 480, "Force 3");
	disp->addScene(menu);
	disp->switchScene(SCENE_MENU);
	disp->start(true);

	delete disp;
}