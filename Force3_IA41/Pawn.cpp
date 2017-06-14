#include "Pawn.h"
#include <iostream>
#include "Game.h"


Pawn::Pawn(sf::String name) : GameObject(name)
{
	playerID = 0;	
}

Pawn::~Pawn()
{
}

int Pawn::GetPlayerID() {
	return playerID;
}

void Pawn::SetPlayerID(int value) {
	playerID = value;
}

void Pawn::setPosition(int x, int y)
{
	if(playerID > 0)
		spriteComp->setPosition(x, y);

}

void Pawn::SetPawn(int playerID, int x, int y)
{
	SetPlayerID(playerID);
	sf::String _image;
	
	if (playerID == 1)
		_image = "ressources/pawn_j1.png";
	else if (playerID == 2)
		_image = "ressouces/pawn_j2.png";

	spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, _image);
	spriteComp->setPosition(x, y);
	addComponent(spriteComp);
}

void Pawn::init(Display * _disp)
{
	GameObject::init(_disp);
}

void Pawn::update(Display * _disp, sf::Event & _event)
{
	GameObject::update(_disp, _event);
}

void Pawn::draw(Display * _disp)
{
	GameObject::draw(_disp);
}
