#include "Pawn.h"
#include <iostream>



Pawn::Pawn() : GameObject("null")
{
	playerID = 0;
}

Pawn::Pawn(int playerID) : GameObject(""+playerID){
	SetPlayerID(playerID);

	shape = new sf::CircleShape(50);

	sf::Color background_color;
	sf::Color border_color;

	if (playerID == 1) {
		background_color = sf::Color(185, 35, 35);
		border_color = sf::Color(146, 25, 25);
	}
	else {
		background_color = sf::Color(111, 138, 226);
		border_color = sf::Color(78, 99, 171);
	}

	shape->setFillColor(background_color);
	shape->setOutlineThickness(5);
	shape->setOutlineColor(border_color);

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
	free(shape);
}

int Pawn::GetPlayerID() {
	return playerID;
}

void Pawn::SetPlayerID(int value) {
	playerID = value;
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
	draw(shape);
}
