#pragma once

#include "Scene.h"
#include "Button.h"



/* CONSTANTES */
#define SCENE_MENU "menuScene"

/*
	Classe MenuScene

	Sc�ne qui repr�sente le menu
*/
class MenuScene : public Scene
{
private:
	/* CONSTANTES */
	const sf::String BTN_PLAY = "playButton";
	const sf::String BTN_QUIT = "quitButton";

	Button* playButton;
	Button* quitButton;

public:
	MenuScene();
	~MenuScene();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;
};

