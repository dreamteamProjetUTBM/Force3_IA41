#include "IAPrologScriptComponent.h"
#include <iostream>

IAPrologScriptComponent::IAPrologScriptComponent(sf::String _name, char* arg0) : Component(_name)
{
	plHelper = new PrologHelper(arg0);
	plHelper->consultFile("force3.pl");

	/* Prédicat pour trouver la meilleur solution */
	plHelper->loadPredicat("best_combination", 3);
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

	term_t mm = PL_copy_term_ref(m);

	/* Récupération du résultat */
	while (PL_get_list(mm, m, element))
	{
		int val;
		PL_get_integer(element, &val);

		std::cout << val << std::endl;
	}

	return std::vector<int>();
}