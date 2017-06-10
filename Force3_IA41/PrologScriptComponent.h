#pragma once

#include "PrologHelper.h"

/*
	Classe PrologScriptComponent

	Composant pour ex�cuter des pr�dicats prolog dans les
	GameObjects
*/
class PrologScriptComponent
{
private:
	PrologHelper* plHelper;

public:
	PrologScriptComponent();
	~PrologScriptComponent();
};

