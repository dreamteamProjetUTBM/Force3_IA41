#pragma once

#include <map>
#include <SWI-cpp.h>
#include <SFML\System\String.hpp>

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
};

