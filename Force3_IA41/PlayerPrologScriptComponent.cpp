#include "PlayerPrologScriptComponent.h"

PlayerPrologScriptComponent::PlayerPrologScriptComponent(sf::String _name, char* arg0) : Component(_name)
{
	plHelper = new PrologHelper(arg0);
	
	/* Chargement de tous les prédicats */
	plHelper->loadPredicat("coup_prec", 4);
	plHelper->loadPredicat("action_ia", 3);
	plHelper->loadPredicat("max", 6);
	plHelper->loadPredicat("jouer", 4);
	plHelper->loadPredicat("victoire", 2);
	plHelper->loadPredicat("meilleure", 3);
}

PlayerPrologScriptComponent::~PlayerPrologScriptComponent()
{
	delete plHelper;
}

void PlayerPrologScriptComponent::init(Display* _disp)
{
}

void PlayerPrologScriptComponent::update(Display* _disp, sf::Event& _event)
{

}

void PlayerPrologScriptComponent::draw(Display* _disp)
{
}
