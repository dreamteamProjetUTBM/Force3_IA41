#include "Pawn.h"
#include <iostream>



Pawn::Pawn() : GameObject("null")
{
	playerID = 0;
	//spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, "ressources/pawn_j1.png");
	//spriteComp->setPosition(400, 100);
	//addComponent(spriteComp);
}

Pawn::Pawn(int playerID,sf::String _image) : GameObject(""+playerID){
	SetPlayerID(playerID);

	spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, _image);
	//spriteComp->setPosition(400, 100);
	addComponent(spriteComp);



	clickComp = new ClickableComponent(COMP_CLICK, spriteComp);
	clickComp->setClickedCallback([](SpriteComponent* sc) {
		std::cout << "jeton pressed" << std::endl;

		/*if(c'est ton tour)
		{
			if(clic droit){
				if(pawn.playerID == getCurrentJoueur().playerID){
					le joueur doit choisir une autre case pour déplacer le jeton
				}
			}
		}
		*/

	});
	clickComp->setReleasedCallback([](SpriteComponent* sc) { std::cout << "rel" << std::endl; });
	addComponent(clickComp);
}

Pawn::~Pawn()
{
}

int Pawn::GetPlayerID() {
	return playerID;
}

void Pawn::SetPlayerID(int value) {
	playerID = value;

	if (value == 1) 
		spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, "ressources/pawn_j1.png");
	else
		spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, "ressources/pawn_j2.png");
	
}

void Pawn::setPosition(int x, int y)
{
	spriteComp->setPosition(x, y);
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
