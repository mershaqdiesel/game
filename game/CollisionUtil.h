#ifndef __GAME_COLLISIONUTIL
#define __GAME_COLLISIONUTIL

#include <iostream>
#include <memory>

#include "ColliderComponent.h"
#include "CircleCollider.h"
#include "AABBCollider.h"

namespace game
{
	class CollisionUtil
	{
	public:
		static bool CollidesWith(std::shared_ptr<ColliderComponent>& a, std::shared_ptr<ColliderComponent>& b);
		static void Resolve(std::shared_ptr<ColliderComponent>& a, std::shared_ptr<ColliderComponent>& b);

	private:
		static bool CircleOnCircle(std::shared_ptr<CircleCollider>& a, std::shared_ptr<CircleCollider>& b);
		static bool AABBOnAABB(std::shared_ptr<AABBCollider>& a, std::shared_ptr<AABBCollider>& b);

	};
}

#endif // __GAME_COLLISIONUTIL