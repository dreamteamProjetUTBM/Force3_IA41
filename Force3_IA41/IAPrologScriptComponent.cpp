#include "IAPrologScriptComponent.h"

IAPrologScriptComponent::IAPrologScriptComponent(sf::String _name, char* arg0) : Component(_name)
{
	plHelper = new PrologHelper(arg0);
}

IAPrologScriptComponent::~IAPrologScriptComponent()
{
	delete plHelper;
}

void IAPrologScriptComponent::init(Display* _disp)
{
}

void IAPrologScriptComponent::update(Display* _disp, sf::Event& _event)
{
}

void IAPrologScriptComponent::draw(Display* _disp)
{
}
