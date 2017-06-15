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
