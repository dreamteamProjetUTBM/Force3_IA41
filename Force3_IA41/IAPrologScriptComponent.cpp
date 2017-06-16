#include "IAPrologScriptComponent.h"
#include <iostream>

IAPrologScriptComponent::IAPrologScriptComponent(sf::String _name, char* arg0) : Component(_name)
{
	plHelper = new PrologHelper(arg0);
	bool r = plHelper->consultFile("force3.pl");
	if (r) std::cout << "OK" << std::endl;
	else std::cout << "FAIL" << std::endl;

	/* Prédicat pour trouver la meilleur solution */
	r = plHelper->loadPredicat("best_combination", 3);
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

std::vector<int> IAPrologScriptComponent::bestCombination(std::vector<int> _board)
{
	term_t b = PL_new_term_refs(3);
	term_t p = b + 1;
	term_t m = b + 2;

	term_t element = PL_new_term_ref();

	for (int i = 0; i < _board.size(); i++)
	{
		PL_put_integer(element, _board[i]);
		PL_cons_list(b, b, element);
	}

	PL_put_integer(p, 2);

	plHelper->callPredicat("best_combination", b);

	term_t tail = PL_new_term_ref();
	while (PL_get_list(m, m, tail))
	{
		int val;
		PL_get_integer(tail, &val);

		std::cout << val << std::endl;
	}

	return std::vector<int>();
}