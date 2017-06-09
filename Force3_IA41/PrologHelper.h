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

	bool consultFile(sf::String _file);
};

