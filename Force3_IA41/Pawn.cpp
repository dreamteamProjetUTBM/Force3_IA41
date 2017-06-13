#include "Pawn.h"
#include <iostream>



Pawn::Pawn(sf::String name) : GameObject(name)
{

	playerID = 0;

	clickComp = new ClickableComponent(COMP_CLICK, spriteComp);
	clickComp->setLeftClickedCallback([](SpriteComponent* sc) {
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
	clickComp->setRightClickCallback([](SpriteComponent* sc) { std::cout << "right click on pawn" << std::endl; });
	clickComp->setReleasedCallback([](SpriteComponent* sc) { std::cout << "rel" << std::endl; });

	//addComponent(clickComp);
	
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
