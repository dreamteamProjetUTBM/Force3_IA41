#include "IAPrologScriptComponent.h"
#include <iostream>

IAPrologScriptComponent::IAPrologScriptComponent(sf::String _name, char* arg0) : Component(_name)
{
	plHelper = new PrologHelper(arg0);
	bool r = plHelper->consultFile("force3.pl");
	if (r) std::cout << "OK" << std::endl;
	else std::cout << "FAIL" << std::endl;

	/* Prédicat pour trouver la meilleur solution */
	r = plHelper->loadPredicat("best_combination", 4);
	if (r) std::cout << "OK" << std::endl;
	else std::cout << "FAIL" << std::endl;

	r = plHelper->loadPredicat("win", 2);
	if (r) std::cout << "OK" << std::endl;
	else std::cout << "FAIL" << std::endl;
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

std::vector<int> IAPrologScriptComponent::bestCombination(std::vector<int> _board, std::vector<int> _prev)
{
	term_t b = PL_new_term_refs(4);
	term_t p = b + 1;
	term_t o = b + 2;
	term_t m = b + 3;

	PrologHelper::setList(b, _board);
	PrologHelper::setList(o, _prev);

	PL_put_integer(p, 2);

	plHelper->callPredicat("best_combination", b);

	return PrologHelper::getList(m);
}

bool IAPrologScriptComponent::win(std::vector<int> _board,int _player)
{
	term_t b = PL_new_term_refs(2);
	term_t p = b + 1;

	PrologHelper::setList(b, _board);

	PL_put_integer(p, _player);

	return plHelper->callPredicat("win", b);
}