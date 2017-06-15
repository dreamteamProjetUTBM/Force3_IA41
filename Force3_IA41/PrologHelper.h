#pragma once

#include <map>
#include <SWI-cpp.h>
#include <SFML\System\String.hpp>

/* CONSTANTES */
#define PRED_CONSULT "consult"

/*
	Classe PrologHelper

	Fournis un moyen plus simple de g�rer prolog
*/
class PrologHelper
{
private:
	/* Le moteur prolog */
	PlEngine engine;
	/* Identifiant du contexte ouvert */
	fid_t frame_id;

	/* Permet de stocker plusieurs pr�dicats dans le contexte */
	std::map<sf::String, predicate_t> predicats;

public:
	PrologHelper(char* arg0);
	~PrologHelper();

	/* Permet de consulter un fichier pl */
	bool consultFile(sf::String _file);
	/* Permet de charger un pr�dicat */
	bool loadPredicat(sf::String _pred, int _nbparam);
	/* Permet d'appeler un predicat dans le cas ou il � �t� charg� auparavant */
	bool callPredicat(sf::String _pred, term_t _term);

	qid_t openQuery(sf::String _pred, term_t _term);
	void closeQuery(qid_t _query_id);

	bool getNextSolution(qid_t _query_id);
};

