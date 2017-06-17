#include "Case.h"
#include <iostream>
#include "Game.h"

Case::Case(sf::String _name, sf::String _image, int x, int y, bool isempty) : GameObject(_name)
{
	_isEmpty = isempty;
	my_pawn = new Pawn(getName() + " Pawn");
	spriteComp = new SpriteComponent(COMP_SPRITE_INACTIVE, _image);

	spriteComp->setPosition(x,y);
	addComponent(spriteComp);

	clickComp = new ClickableComponent(COMP_CLICK, spriteComp);
	enableClick();
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

void Case::setPosition(int x, int y)
{
	spriteComp->setPosition(sf::Vector2f(x, y));
	if(!isEmpty())
		my_pawn->setPosition(x, y);
	_ajouer = true;
}

sf::Vector2f Case::getPosition()
{
	return spriteComp->getPosition();
}

bool Case::isEmpty()
{
	return _isEmpty;
}

void Case::enableClick()
{
	clickComp->setLeftClickedCallback([this](SpriteComponent* sc) {
		//std::cout << "LC Case" << std::endl;
		//if (game.getPlayersTurn() == 1)
		//{
		disableClick();
		if (!Game::Instance().getCoupEnCours()) {
			std::cout << "Premier coup" << std::endl;
			Game::Instance().setOldPosition(this);
			Game::Instance().setCoupEnCours(true);
		}
		else
		{
			std::cout << "Second coup" << std::endl;
			Game::Instance().setNewPosition(this);
			Game::Instance().joue(1);
			Game::Instance().setCoupEnCours(false);
		}
		enableClick();
		//}
	});

	clickComp->setRightClickCallback([this](SpriteComponent* sc) {
		//std::cout << "RG Case" << std::endl;
		if (isEmpty()) {
			std::cout << "You can't add a pawn here" << std::endl;
			return;
		}
		Game::Instance().setOldPosition(this);
		Game::Instance().joue(0);

	});

	clickComp->setReleasedCallback([this](SpriteComponent* sc) {  });
}

void Case::disableClick()
{
	clickComp->setLeftClickedCallback([this](SpriteComponent* sc) { 
		//std::cout << "left click disabled" << std::endl; 
	});
	clickComp->setRightClickCallback([this](SpriteComponent* sc) {
		//std::cout << "right click disabled" << std::endl;
	});
	clickComp->setReleasedCallback([this](SpriteComponent* sc) {
		//std::cout << "released click disabled" << std::endl; 
	});

}

void Case::init(Display * _disp)
{
	GameObject::init(_disp);
}

void Case::update(Display * _disp, sf::Event & _event)
{
	if(_ajouer)
		disableClick();
	GameObject::update(_disp, _event);
	if (_ajouer) {
		enableClick();
		_ajouer = false;
	}
}

void Case::draw(Display * _disp)
{
	GameObject::draw(_disp);
}
