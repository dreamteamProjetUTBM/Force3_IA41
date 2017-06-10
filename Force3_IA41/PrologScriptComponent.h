#pragma once

#include "PrologHelper.h"

/*
	Classe PrologScriptComponent

	Composant pour exécuter des prédicats prolog dans les
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

