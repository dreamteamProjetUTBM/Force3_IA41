#include "Display.h"
#include "Scene.h"

Display::Display(int _w, int _h, sf::String _t) : window(), clearColor(), activeScene(nullptr)
{
	window.create(sf::VideoMode(_w, _h), _t);
	window.setVisible(true);
}

Display::~Display()
{
	for (auto scene : scenes)
	{
		delete scene;
	}
	scenes.clear();
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
		if (activeScene != nullptr)
			activeScene->update(this);

		window.clear(clearColor);
		if (activeScene != nullptr)
			activeScene->draw(this);
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

bool Display::addScene(Scene * _scen)
{
	sf::String n = _scen->getName();
	for (auto scene : scenes)
	{
		if (scene->getName() == n)
		{
			return false;
		}
	}

	scenes.push_back(_scen);
	return true;
}

bool Display::switchScene(sf::String _name)
{
	for (auto scene : scenes)
	{
		if (scene->getName() == _name)
		{
			activeScene = scene;
			activeScene->init(this);
			return true;
		}
	}

	return false;
}

void Display::draw(sf::Drawable * _shap)
{
	window.draw(*_shap);
}
