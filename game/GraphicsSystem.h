#ifndef __GAME_GRAPHICSSYSTEM
#define __GAME_GRAPHICSSYSTEM

#include <memory>
#include <vector>

#include <SFML\Graphics.hpp>

#include "GraphicComponent.h"
#include "CircleGraphic.h"
#include "Camera.h"

namespace game
{
	class GraphicsSystem
	{
	public:
		GraphicsSystem();
		~GraphicsSystem();

		void Render(sf::RenderTarget& target);

		std::shared_ptr<game::GraphicComponent> Create(const std::string type, std::shared_ptr<Entity> parent);

	private:
		std::vector<std::shared_ptr<GraphicComponent> > _graphicComponents;
		Camera _mainCamera;
	};
}

#endif // __GAME_GRAPHICSSYSTEM