#ifndef __GAME_GRAPHICCOMPONENT
#define __GAME_GRAPHICCOMPONENT

#include <string>

#include <SFML\Graphics.hpp>

#include "Component.h"

namespace game
{
	class GraphicComponent : public Component
	{
	public:
		GraphicComponent(std::string t) : Component(t) {};
		virtual ~GraphicComponent();
		virtual void Draw(sf::RenderTarget& target) {};
	};
}

#endif // __GAME_GRAPHICCOMPONENT