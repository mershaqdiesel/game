#ifndef __GAME_PHYSICSSYSTEM
#define __GAME_PHYSICSSYSTEM

#include <memory>
#include <vector>

#include "Entity.h"
#include "PhysicsComponent.h"
#include "RigidBody.h"
#include "ColliderComponent.h"
#include "CollisionUtil.h"

namespace game
{
	class PhysicsSystem
	{
	public:
		PhysicsSystem();
		~PhysicsSystem();

		void Update(float time);

		std::shared_ptr<PhysicsComponent> Create(std::string name, std::shared_ptr<Entity> _parent);

	private:
		std::vector<std::shared_ptr<RigidBody> > _rigidBodies;
		std::vector<std::shared_ptr<ColliderComponent> > _colliders;
	};
}

#endif // __GAME_PHYSICSSYSTEM