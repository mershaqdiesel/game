#include "CircleGraphic.h"

game::CircleGraphic::CircleGraphic()
	: GraphicComponent(typeid(CircleGraphic).name()), _circle()
{
}

game::CircleGraphic::CircleGraphic(float radius)
	: GraphicComponent(typeid(CircleGraphic).name()), _circle(radius)
{
}

game::CircleGraphic::CircleGraphic(float radius, sf::Color& color)
	: GraphicComponent(typeid(CircleGraphic).name()), _circle(radius)
{
	SetColor(color);
}

game::CircleGraphic::CircleGraphic(float radius, const sf::Color color)
	: GraphicComponent(typeid(CircleGraphic).name()), _circle(radius)
{
	_circle.setFillColor(color);
}

game::CircleGraphic::~CircleGraphic()
{
}

void game::CircleGraphic::SetSize(float radius)
{
	_circle.setRadius(radius);
}

float game::CircleGraphic::GetSize()
{
	return _circle.getRadius();
}

void game::CircleGraphic::SetColor(const sf::Color color)
{
	_circle.setFillColor(color);
}

sf::Color game::CircleGraphic::GetColor()
{
	return _circle.getFillColor();
}

void game::CircleGraphic::Draw(sf::RenderTarget& target)
{
	sf::Transform t = _parent->CalcTransform();
	sf::RenderStates states(t);
	target.draw(_circle, states);
}