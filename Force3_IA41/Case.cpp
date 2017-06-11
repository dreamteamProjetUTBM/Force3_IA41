#include "Case.h"
#include <iostream>


Case::Case(sf::String _name, sf::String _image, int x, int y) : GameObject(_name)
{
	spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, _image);

	spriteComp->setPosition(x,y);
	addComponent(spriteComp);


	clickComp = new ClickableComponent(COMP_CLICK, spriteComp);
	clickComp->setClickedCallback([](SpriteComponent* sc) { 
		std::cout << "case pressed" << std::endl; 
		
		/*if(c'est ton tour)
		{
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
			}
		}
		*/
	
	});
	clickComp->setReleasedCallback([](SpriteComponent* sc) { std::cout << "rel" << std::endl; });
	addComponent(clickComp);

	my_pawn = new Pawn();

}

Case::Case() : GameObject("null"){

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
	//my_pawn->setPosition(spriteComp->getPosition().x, spriteComp->getPosition().y);
	my_pawn->setPosition(0,0);
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
