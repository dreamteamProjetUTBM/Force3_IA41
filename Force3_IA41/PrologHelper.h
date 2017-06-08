#pragma once

#include <map>
#include <SWI-cpp.h>
#include <SFML\System\String.hpp>

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
};

