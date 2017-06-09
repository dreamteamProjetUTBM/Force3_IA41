#pragma once

#include "Scene.h"

/* CONSTANTES */
#define SCENE_MENU "menuScene"

/*
	Classe MenuScene

	Scène qui représente le menu
*/
class MenuScene : public Scene
{
private:

public:
	MenuScene();
	~MenuScene();

	void init(Display* _disp) override;
	void update(Display* _disp) override;
	void draw(Display* _disp) override;
};

