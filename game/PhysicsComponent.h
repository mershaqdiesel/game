#ifndef __GAME_PHYSICSCOMPONENT
#define __GAME_PHYSICSCOMPONENT

#include "Component.h"

namespace game
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent(std::string type) : Component(type) {}
		virtual ~PhysicsComponent()=0;
	};
}

#endif // __GAME_PHYSICSCOMPONENT