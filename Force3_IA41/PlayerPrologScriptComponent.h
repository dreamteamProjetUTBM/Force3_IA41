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

	/* Permet de vérifier que l'action suivante n'est pas la même que la précédente */
	bool previousAction(/*P, */ int _pawn_id, int _prev_action[], int _next_action);
	void play();
	/* Regarde si les pions d'un joueur ne sont pas dans une configuration de victoire */
	bool victory(int _pawn_id);
};
