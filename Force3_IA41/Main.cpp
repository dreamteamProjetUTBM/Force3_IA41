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

	IAPrologScriptComponent* s = new IAPrologScriptComponent("test", argv[0]);
	std::vector<int> b;
	b.push_back(1);
	b.push_back(0);
	b.push_back(1);

	b.push_back(0);
	b.push_back(-1);
	b.push_back(0);

	b.push_back(2);
	b.push_back(0);
	b.push_back(2);

	auto v = s->bestCombination(b);
	delete s;

	for(int val : v)
	{
		std::cout << val << std::endl;
	}

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