#include "GraphicsSystem.h"

game::GraphicsSystem::GraphicsSystem() : _graphicComponents(), _mainCamera()
{

}

game::GraphicsSystem::~GraphicsSystem()
{

}

void game::GraphicsSystem::Render(sf::RenderTarget& target)
{
	target.setView(_mainCamera.GetView());
	for (auto graphic : _graphicComponents)
	{
		graphic->Draw(target);
	}
}

std::shared_ptr<game::GraphicComponent> game::GraphicsSystem::Create(const std::string type, std::shared_ptr<Entity> parent)
{
	if (type.compare(typeid(CircleGraphic).name()) == 0)
	{
		std::shared_ptr<GraphicComponent> cg(new CircleGraphic());
		if (parent->AddComponent(cg))
		{
			cg->SetParent(parent);
			_graphicComponents.push_back(cg);
			return cg;
		}
	}
	return nullptr;
}