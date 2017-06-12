#include "TextSpriteComponent.h"

TextSpriteComponent::TextSpriteComponent(sf::String _name, sf::String _text, sf::String _font) : Component(_name)
{
	font.loadFromFile(_font);

	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setString(_text);
}

TextSpriteComponent::~TextSpriteComponent()
{
}

void TextSpriteComponent::init(Display* _disp)
{
}

void TextSpriteComponent::update(Display* _disp, sf::Event& _event)
{
}

void TextSpriteComponent::draw(Display* _disp)
{
	_disp->draw(&text);
}

void TextSpriteComponent::setText(sf::String _text)
{
	text.setString(_text);
}

void TextSpriteComponent::setColor(int _r, int _g, int _b)
{
	text.setFillColor(sf::Color(_r, _g, _b));
}

void TextSpriteComponent::setPosition(sf::Vector2f _pos)
{
	text.setPosition(_pos);
}

void TextSpriteComponent::setPosition(float _x, float _y)
{
	text.setPosition(_x, _y);
}

sf::Vector2f TextSpriteComponent::getPosition() const
{
	return text.getPosition();
}
