/*
	Projet Force3 IA41
*/
#include <iostream>
#include <SWI-cpp.h>

#include "Display.h"

int main(int argc, char* argv[]) 
{
	/* Permet de mettre en place l'environnement !!! Obligatoire sinon ça ne
	 fonctionne pas du tout !!!*/
	//ATTENTION : Thomas j'ai changé le "pl" en "swipl"
	_putenv("SWI_HOME_DIR=C:\\Program Files (x86)\\pl\\");

	PlEngine engine(argv[0]);

	/* Ouverture d'un contexte prolog */
	fid_t fid= PL_open_foreign_frame();

	predicate_t pred = PL_predicate("consult", 1, "user");
	term_t t1 = PL_new_term_ref();
	PL_put_string_chars(t1, "test.pl");
	
	int r = PL_call_predicate(NULL, PL_Q_NODEBUG, pred, t1);
	if (r)
	{
		std::cout << "Ok ! " << std::endl;
	}
	else
	{
		std::cout << "Fail !" << r << std::endl;
	}

	predicate_t pred1 = PL_predicate("factoriel", 1, "user");
	term_t t2 = PL_new_term_ref();
	PL_put_integer(t2, 5);

	int r2 = PL_call_predicate(NULL, PL_Q_NODEBUG, pred1, t2);
	if (r2)
	{
		std::cout << "Ok ! " << std::endl;
	}
	else
	{
		std::cout << "Fail !" << r << std::endl;
	}

	/* Fermeture du contexte prolog */
	PL_close_foreign_frame(fid);

	Display* disp = new Display(854, 480, "Force 3");
	disp->start(true);
}