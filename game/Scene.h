#ifndef __GAME_SCENE
#define __GAME_SCENE

#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "BehaviorSystem.h"
#include "Entity.h"
#include "GraphicsSystem.h"
#include "PhysicsSystem.h"

namespace game
{
	class Scene
	{
	public:
		Scene();
		Scene(std::string fname);
		~Scene();

		void Load(std::string fname);

		void Init();

		void Update(float secs);				// will occur as fast as possible
		void PhysicsUpdate(float secs);			// should occur at regular intervals ~ 2ms
		void Draw(sf::RenderTarget& target);
		void HandleInput(sf::Event& event);

	private:
		std::vector<std::shared_ptr<Entity> > _entities;
		std::string _title;

		GraphicsSystem _graphics;
		BehaviorSystem _behaviors;
		PhysicsSystem _physics;

		static int _numTotalScenes;
	};
}

#endif // __GAME_SCENE