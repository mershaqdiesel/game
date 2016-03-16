#ifndef __GAME_ENTITY
#define __GAME_ENTITY

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

namespace game
{
	class Component;

	class Entity
	{
	public:
		Entity();
		~Entity();

		std::shared_ptr<Component> GetComponent(std::string name);
		bool AddComponent(std::shared_ptr<Component> comp);

		sf::Transform CalcTransform();

		sf::Transformable transform;

	private:
		std::shared_ptr<Entity> _parent;
		std::vector<std::shared_ptr<Entity> > _children;
		std::vector<std::shared_ptr<Component> > _components;
	};
}

#endif