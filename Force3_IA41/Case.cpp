#include "Case.h"
#include <iostream>


Case::Case(sf::String _name, sf::String _image, int x, int y) : GameObject(_name)
{
	spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, _image);
	addComponent(spriteComp);


	spriteComp->setPosition(x,y);

	/*clickComp = new ClickableComponent(COMP_CLICK, spriteComp);
	clickComp->setClickedCallback(_click);
	clickComp->setReleasedCallback(_release);
	addComponent(clickComp);*/
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


Pawn Case::GetPawn() {
	return _pawn;
}

void Case::SetPawn(Pawn value) {
	_pawn = value;
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
