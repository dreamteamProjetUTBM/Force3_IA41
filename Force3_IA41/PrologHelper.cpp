#include "PrologHelper.h"

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
