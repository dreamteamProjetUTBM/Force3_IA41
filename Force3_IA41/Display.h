#pragma once

#include <SFML\Graphics.hpp>

class Scene;

/*
	Classe Display

	Gestion de la fenêtre, de l'affichage mais aussi des entrées
	utilisateur
*/
class Display
{
private:
	sf::RenderWindow window;
	sf::Color clearColor;

public:
	Display(int _w, int _h, sf::String _t);
	~Display();

	void start(bool _vsync);

	void setClearColor(sf::Color _c);
	void setClearColor(int _r, int _g, int _b);

	void addScene(Scene* _scen);
};

