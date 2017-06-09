#include "PrologHelper.h"

PrologHelper::PrologHelper(char* arg0) : engine(arg0)
{
	/* Ouvrire le context */
	frame_id = PL_open_foreign_frame();

	/* Chargement du pr�dicat consult */
	predicats.insert(std::pair<sf::String, predicate_t>(PRED_CONSULT, PL_predicate(PRED_CONSULT, 1, "user")));
}

PrologHelper::~PrologHelper()
{
	/* Fermer le context */
	PL_close_foreign_frame(frame_id);
}

bool PrologHelper::consultFile(sf::String _file)
{
	/* Cr�ation du param�tre pour le pr�dicat consult */
	term_t term = PL_new_term_ref();
	PL_put_string_chars(term, _file.toAnsiString().c_str());

	int result = PL_call_predicate(NULL, PL_Q_NODEBUG, predicats[PRED_CONSULT], term);
	return result;
}

bool PrologHelper::loadPredicat(sf::String _pred, int _nbparam)
{
	return false;
}

bool PrologHelper::callPredicat(sf::String _pred, term_t _term)
{
	return false;
}
