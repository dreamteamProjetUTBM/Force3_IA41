/*
	Projet Force3 IA41
*/
#include <iostream>

#include <SFML\Graphics.hpp>
#include <SWI-cpp.h>

int main(int argc, char* argv[]) 
{

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(854, 480), "Force 3", sf::Style::Default, settings);
	//sf::RenderWindow window;
	//window.create(sf::VideoMode(854, 480), "Force 3");
	window.setVerticalSyncEnabled(true);
	

	/* Permet de mettre en place l'environnement !!! Obligatoire sinon ça ne
	 fonctionne pas du tout !!!*/
	//ATTENTION : Thomas j'ai changé le "pl" en "swipl"
	_putenv("SWI_HOME_DIR=C:\\Program Files (x86)\\swipl\\");

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

	/*Graphical components*/

	//Il faut définir une Font avant de pouvoir afficher
	//sf::Text title;
	//title.setString("Force 3");
	//title.setCharacterSize(24);
	//title.setFillColor(sf::Color::Red);

	/*Aspect pion 1*/
	sf::CircleShape pawn_j1(50);
	pawn_j1.setFillColor(sf::Color(185, 35, 35));
	pawn_j1.setOutlineThickness(5);
	pawn_j1.setOutlineColor(sf::Color(146, 25, 25));
	pawn_j1.setPosition(50, 50);

	/*Aspect pion 2*/
	sf::CircleShape pawn_j2(50);
	pawn_j2.setFillColor(sf::Color(111, 138, 226));
	pawn_j2.setOutlineThickness(5);
	pawn_j2.setOutlineColor(sf::Color(78, 99, 171));
	pawn_j2.setPosition(200, 50);

	/*Aspect case*/
	sf::Texture texture;
	if (!texture.loadFromFile("..\\Ressources\\case.jpg"))
	{
		// error...
	}
	sf::RectangleShape case_aspect(sf::Vector2f(150, 150));
	case_aspect.setTexture(&texture); // texture is a sf::Texture
	case_aspect.setTextureRect(sf::IntRect(10, 10, 150, 150));
	case_aspect.setPosition(50, 200);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		//window.draw(title);
		window.draw(pawn_j1);
		window.draw(pawn_j2);
		window.draw(case_aspect);
		window.display();
	}
}