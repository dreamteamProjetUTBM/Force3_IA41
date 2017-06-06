#include "Display.h"
#include "Scene.h"

Display::Display(int _w, int _h, sf::String _t) : window(), clearColor()
{
	window.create(sf::VideoMode(_w, _h), _t);
	window.setVisible(true);
}

Display::~Display()
{
}

void Display::start(bool _vsync)
{
	window.setVerticalSyncEnabled(_vsync);

	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window.close();
		}

		window.clear(clearColor);
		window.display();
	}
}

void Display::setClearColor(sf::Color _c)
{
	clearColor = _c;
}

void Display::setClearColor(int _r, int _g, int _b)
{
	clearColor.r = _r;
	clearColor.g = _g;
	clearColor.b = _b;
}

void Display::addScene(Scene * _scen)
{
}
