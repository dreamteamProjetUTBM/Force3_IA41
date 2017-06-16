#include "PrologHelper.h"
#include <iostream>

PrologHelper::PrologHelper(char* arg0) : engine(arg0)
{
	/* Ouvrire le context */
	frame_id = PL_open_foreign_frame();

	/* Chargement du prédicat consult */
	predicats.insert(std::pair<sf::String, predicate_t>(PRED_CONSULT, PL_predicate(PRED_CONSULT, 1, "user")));
}

PrologHelper::~PrologHelper()
{
	/* Fermer le context */
	PL_close_foreign_frame(frame_id);
}

bool PrologHelper::consultFile(sf::String _file)
{
	/* Création du paramètre pour le prédicat consult */
	term_t term = PL_new_term_ref();
	PL_put_string_chars(term, _file.toAnsiString().c_str());

	int result = PL_call_predicate(NULL, PL_Q_NODEBUG, predicats[PRED_CONSULT], term);
	return result;
}

bool PrologHelper::loadPredicat(sf::String _pred, int _nbparam)
{
	const char* name = _pred.toAnsiString().c_str();
	predicate_t pred = PL_predicate(name, _nbparam, "user");

	if (pred == NULL)
	{
		std::cout << "[ERREUR] Impossible de charger le prédicat :" << _pred.toAnsiString() << std::endl;
		return false;
	}

	predicats.insert(std::pair<sf::String, predicate_t>(name, pred));

	return true;
}

bool PrologHelper::callPredicat(sf::String _pred, term_t _term)
{
	int result = PL_call_predicate(NULL, PL_Q_NODEBUG, predicats[_pred], _term);
	return result;
}

qid_t PrologHelper::openQuery(sf::String _pred, term_t _term)
{
	qid_t id = PL_open_query(NULL, PL_Q_NORMAL, predicats[_pred], _term);
	return id;
}

void PrologHelper::closeQuery(qid_t _query_id)
{
	PL_close_query(_query_id);
}

bool PrologHelper::getNextSolution(qid_t _query_id)
{
	return PL_next_solution(_query_id);
}

/*STATIC*/
void PrologHelper::setList(term_t& _list, std::vector<int> _values)
{
	term_t element = PL_new_term_ref();
	PL_put_nil(_list);
	std::vector<int> inverse_values;

	for(int i = _values.size() - 1; i >= 0; i--)
	{
		inverse_values.push_back(_values[i]);
	}

	for (int i = 0; i < inverse_values.size(); i++)
	{
		PL_put_integer(element, inverse_values[i]);
		PL_cons_list(_list, element, _list);
	}
}

/*STATIC*/
std::vector<int> PrologHelper::getList(term_t& _list)
{
	std::vector<int> result;

	term_t head = PL_new_term_ref();
	term_t list = PL_copy_term_ref(_list);
	while (PL_get_list(list, head, list))
	{
		int val;
		PL_get_integer(head, &val);
		result.push_back(val);
	}

	return result;
}

