#pragma once

#include "Component.h"
#include "PrologHelper.h"

/* CONSTANTES */
const int PAWN_PLACEMENT	= 0;
const int PAWN_MOVE			= 1;
const int CASE_SINGLE_MOVE	= 2;
const int CASE_DOUBLE_MOVE	= 3;

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

	bool isPossible(std::vector<int> _board, std::vector<int> _move);
};
