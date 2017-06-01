/*
	Projet Force3 IA41
*/
#include <iostream>

#include <SFML\Graphics.hpp>
#include <SWI-cpp.h>

int main(int argc, char* argv[]) 
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(854, 480), "Force 3");
	window.setVerticalSyncEnabled(true);

	// Permet de mettre en place l'environnement !!! Obligatoire sinon ça ne
	// fonctionne pas du tout !!!
	_putenv("SWI_HOME_DIR=C:\\Program Files (x86)\\pl\\");

	PlEngine engine(argv[0]);

	// Mettre les fichier prolog au même niveau que l'exécutable...
	PlCall("consult('test')");

	PlTermv term(1);
	term[0] = 4;
	PlQuery query("factoriel", term);

	while (int r = query.next_solution() > 0)
	{
		std::cout << (bool)r << std::endl;
	}

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
		window.display();
	}
}