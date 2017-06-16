#pragma once

#include <map>
#include <SWI-cpp.h>
#include <SFML\System\String.hpp>
#include <vector>

/* CONSTANTES */
#define PRED_CONSULT "consult"

/*
	Classe PrologHelper

	Fournis un moyen plus simple de gérer prolog
*/
class PrologHelper
{
private:
	/* Le moteur prolog */
	PlEngine engine;
	/* Identifiant du contexte ouvert */
	fid_t frame_id;

	/* Permet de stocker plusieurs prédicats dans le contexte */
	std::map<sf::String, predicate_t> predicats;

public:
	PrologHelper(char* arg0);
	~PrologHelper();

	/* Permet de consulter un fichier pl */
	bool consultFile(sf::String _file);
	/* Permet de charger un prédicat */
	bool loadPredicat(sf::String _pred, int _nbparam);
	/* Permet d'appeler un predicat dans le cas ou il à été chargé auparavant */
	bool callPredicat(sf::String _pred, term_t _term);

	qid_t openQuery(sf::String _pred, term_t _term);
	void closeQuery(qid_t _query_id);

	bool getNextSolution(qid_t _query_id);

	/*
	 * METHODES STATIQUES
	 */
	/* Permet d'affecter les valeurs (integer) d'un vecteur dans une liste pl */
	static void setList(term_t& _list, std::vector<int> _values);
	/* Permet de récupérer les valeurs d'une liste pl dans un vecteur */
	static std::vector<int> getList(term_t& _list);
};

