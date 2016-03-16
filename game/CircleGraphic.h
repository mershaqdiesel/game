#ifndef __GAME_CIRCLEGRAPHIC
#define __GAME_CIRCLEGRAPHIC

#include <iostream>

#include <SFML\Graphics\CircleShape.hpp>

#include "GraphicComponent.h"

namespace game
{
	class CircleGraphic : public GraphicComponent
	{
	public:
		CircleGraphic();
		CircleGraphic(float radius);
		CircleGraphic(float radius, sf::Color& color);
		CircleGraphic(float radius, const sf::Color color);

		~CircleGraphic();

		void SetSize(float radius);
		float GetSize();

		void SetColor(const sf::Color color);
		sf::Color GetColor();

		void Draw(sf::RenderTarget& target);

	private:
		sf::CircleShape _circle;
	};
}

#endif // __GAME_CIRCLEGRAPHIC