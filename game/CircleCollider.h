#ifndef __GAME_CIRCLECOLLIDER
#define __GAME_CIRCLECOLLIDER

#include "ColliderComponent.h"

namespace game
{
	class CircleCollider : public ColliderComponent
	{
	public:
		CircleCollider(std::shared_ptr<RigidBody> rb) : ColliderComponent(typeid(CircleCollider).name(), rb) { _radius = 10.0f; };
		CircleCollider(float rad, std::shared_ptr<RigidBody> rb) : ColliderComponent(typeid(CircleCollider).name(), rb) { _radius = rad; };
		~CircleCollider() {};

		float GetRadius() { return _radius; };
		void SetRadius(float rad) { _radius = rad; };

	private:
		float _radius;
	};
}

#endif // __GAME_CIRCLECOLLIDER