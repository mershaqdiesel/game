#ifndef __GAME_BEHAVIORSYSTEM
#define __GAME_BEHAVIORSYSTEM

#include <functional>
#include <memory>
#include <vector>

#include "Behavior.h"

namespace game
{
	class BehaviorSystem
	{
	public:
		BehaviorSystem();
		~BehaviorSystem();

		void Start();
		void UpdateAll(float deltaTime);

		// adds a behavior to the system for updates
		void AddBehavior(std::shared_ptr<Behavior> behavior, std::shared_ptr<Entity> _parent);

	private:
		std::vector<std::shared_ptr<Behavior> > _behaviors;
	};
}

#endif // __GAME_BEHAVIORSYSTEM