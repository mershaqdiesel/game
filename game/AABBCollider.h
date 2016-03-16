#ifndef __GAME_AABBCOLLIDER
#define __GAME_AABBCOLLIDER

#include "ColliderComponent.h"

namespace game
{
	class AABBCollider : public ColliderComponent
	{
	public:
		AABBCollider(std::shared_ptr<RigidBody> rb) : ColliderComponent(typeid(AABBCollider).name(), rb) {};
	};
}

#endif // __GAME_AABBCOLLIDER