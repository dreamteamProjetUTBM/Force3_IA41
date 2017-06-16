﻿#include "PlayerPrologScriptComponent.h"

PlayerPrologScriptComponent::PlayerPrologScriptComponent(sf::String _name, char* arg0) : Component(_name)
{
	plHelper = new PrologHelper(arg0);
	
	plHelper->loadPredicat("is_possible", 3);
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

bool PlayerPrologScriptComponent::isPossible(std::vector<int> _board, std::vector<int> _move)
{
	term_t p = PL_new_term_refs(3);
	term_t j = p + 1;
	term_t m = p + 2;

	PrologHelper::setList(p, _board);
	PL_put_integer(j, 1);

	return plHelper->callPredicat("is_possible", p);
}
