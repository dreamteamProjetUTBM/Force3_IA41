#pragma once

#include "Scene.h"
#include "Button.h"

/* CONSTANTES */
#define SCENE_MENU "menuScene"

/*
	Classe MenuScene

	Scène qui représente le menu
*/
class MenuScene : public Scene
{
private:
	Button* button;

public:
	MenuScene();
	~MenuScene();

	void init(Display* _disp) override;
	void update(Display* _disp) override;
	void draw(Display* _disp) override;
};

