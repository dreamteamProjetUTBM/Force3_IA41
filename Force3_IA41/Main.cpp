/*
	Projet Force3 IA41
*/
#include <iostream>
#include <SWI-cpp.h>

#include "MenuScene.h"
#include "GameScene.h"
#include "Game.h"

#include "IAPrologScriptComponent.h"

int main(int argc, char* argv[])
{
	/* Permet de mettre en place l'environnement !!! Obligatoire sinon ça ne
	 fonctionne pas du tout !!!*/
	_putenv("SWI_HOME_DIR=C:\\Program Files (x86)\\swipl\\");

	IAPrologScriptComponent* ia = new IAPrologScriptComponent("PrologIA", argv[0]);
	PlayerPrologScriptComponent* player = new PlayerPrologScriptComponent("PrologPlayer", argv[0]);


	Scene* menu = new MenuScene();
	GameScene* game = new GameScene(argv[0]);
	Game::Instance().setGameScene(game);

	Game::Instance().iapsc = ia;
	Game::Instance().ppsc = player;

	Display* disp = new Display(854, 480, "Force 3");
	disp->addScene(menu);
	disp->addScene(game);

	disp->switchScene(SCENE_MENU);
	disp->start(true);


	//delete ia;
	//delete player;

	delete disp;
}

/*
 * TODO : Ajouter titre dans le menu
 * TODO : Ajouter affichage du gagnant dans la scène de jeu
 * TODO : Ajouter un bouton recommencer une partie
 */