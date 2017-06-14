#pragma once

#include "GameObject.h"

/* CONSTANTES */
const int PAWN_ID_PLAYER = 1;

/*
 * Classe Player
 * 
 * Représente le joueur et les actions qu'il peut faire
 */
class Player : public GameObject
{
private:

public:
	Player();
	~Player();
};
