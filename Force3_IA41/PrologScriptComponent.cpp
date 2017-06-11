#include "PrologScriptComponent.h"



PrologScriptComponent::PrologScriptComponent(char* arg0)
{
	plHelper = new PrologHelper(arg0);
}


PrologScriptComponent::~PrologScriptComponent()
{
}
