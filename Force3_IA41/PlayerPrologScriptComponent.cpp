#include "PlayerPrologScriptComponent.h"

PlayerPrologScriptComponent::PlayerPrologScriptComponent(sf::String _name, char* arg0) : Component(_name)
{
	plHelper = new PrologHelper(arg0);
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
