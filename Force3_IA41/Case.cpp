#include "Case.h"
#include <iostream>
#include "Game.h"

Case::Case(sf::String _name, sf::String _image, int x, int y) : GameObject(_name)
{
	my_pawn = new Pawn(getName() + " Pawn");
	spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, _image);

	spriteComp->setPosition(x,y);
	addComponent(spriteComp);


	clickComp = new ClickableComponent(COMP_CLICK, spriteComp);
	clickComp->setLeftClickedCallback([this](SpriteComponent* sc) { 
		std::cout << "case pressed" << std::endl; 
		//if (game.getPlayersTurn() == 1)
		//{
			if (!Game::Instance().getCoupEnCours()) {
				std::cout << "Premier coup" << std::endl;
				Game::Instance().setOldPosition(this);

				//Ne change pas le coup..
				Game::Instance().setCoupEnCours(true);
			}
			else
			{
				std::cout << "Second coup" << std::endl;

				Game::Instance().setNewPosition(this);
				Game::Instance().joue(3);
			}


			/*
			if(clic droit){
			if(pawn.playerID == getCurrentJoueur().playerID){
			le joueur doit choisir une autre case pour déplacer la case
			}
			}

			else {
			if(pawn.playerID == 0 && getCurrentJoueur().PawnLeftCount > 0){
			on ajoute un pion
			tour suivant
			}
			}*/
		//}

	
	});

	clickComp->setRightClickCallback([this](SpriteComponent* sc) {
		std::cout << "right click case pressed" << std::endl;

		//SANS CONDITIONS POUR TEST
		if (this->GetPawn()->GetPlayerID() == 0) //&& NbPions du joueur < 3) //On peut ajouter le pion
		{
			//Joueur 1 sera toujours l'humain
			this->GetPawn()->SetPawn(1, this->getPosition().x, this->getPosition().y);
		}


	});

	clickComp->setReleasedCallback([](SpriteComponent* sc) { std::cout << "rel" << std::endl; });
	addComponent(clickComp);

	

}

Case::~Case()
{
}

Case & Case::operator=(Case & _case)
{	

	this->setName(sf::String(_case.getName()));
	return *this;
}


Pawn* Case::GetPawn() {
	return my_pawn;
}

void Case::SetPawn(Pawn* value) {
	my_pawn = value;
}

sf::Vector2f Case::getPosition()
{
	return spriteComp->getPosition();
}

void Case::init(Display * _disp)
{
	GameObject::init(_disp);
}

void Case::update(Display * _disp, sf::Event & _event)
{
	GameObject::update(_disp, _event);
}

void Case::draw(Display * _disp)
{
	GameObject::draw(_disp);
}
