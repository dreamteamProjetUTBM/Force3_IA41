#pragma once

#include "Component.h"
#include "PrologHelper.h"

/*
 * Classe PlayerPrologScriptComponent
 * 
 * Gestion des scripts prolog pour le joueur.
 */
class PlayerPrologScriptComponent : public Component
{
private:
	PrologHelper* plHelper;

	/* Coupe précédent */
	term_t previous;

public:
	PlayerPrologScriptComponent(sf::String _name, char* arg0);
	~PlayerPrologScriptComponent();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;

	bool previousAction();
	void play();
	void victory();
};
