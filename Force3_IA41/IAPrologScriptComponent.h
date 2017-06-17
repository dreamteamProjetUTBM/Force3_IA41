#pragma once

#include "Component.h"
#include "PrologHelper.h"

/*
	Classe IAPrologScriptComponent

	Composant pour ex�cuter des pr�dicats prolog dans les
	GameObjects
*/
class IAPrologScriptComponent : public Component
{
private:
	PrologHelper* plHelper;

public:
	IAPrologScriptComponent(sf::String _name, char* arg0);
	~IAPrologScriptComponent();

	void init(Display* _disp) override;
	void update(Display* _disp, sf::Event& _event) override;
	void draw(Display* _disp) override;

	std::vector<int> bestCombination(std::vector<int> _board, std::vector<int> _prev);
	bool win(std::vector<int> _board, int _player);

};

