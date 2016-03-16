#ifndef __GAME_COLLIDERCOMPONENT
#define __GAME_COLLIDERCOMPONENT

#include <memory>
#include <string>
#include <functional>

#include "PhysicsComponent.h"
#include "RigidBody.h"

namespace game
{
	// Bounding Box Type
	enum BBType
	{
		None,
		Circle,
		AABB,
		NumBBTypes
	};

	class ColliderComponent : public PhysicsComponent
	{
	public:
		friend class CollisionUtil;
		friend class PhysicsSystem;

		ColliderComponent(std::string type, std::shared_ptr<RigidBody>& rb) 
			: PhysicsComponent(type), _rb(rb) { _shape = BBType::None; _isTrigger = false; };

		virtual ~ColliderComponent() {};
		
		void SetTrigger(std::function<void(std::shared_ptr<Entity>&)> trigger) { _trigger = trigger; };
		void OnTrigger(std::shared_ptr<Entity>& other) { if (_isTrigger && _trigger != nullptr) { _trigger(other); } };
		bool IsTrigger() { return _isTrigger; };

		void SetShape(BBType shape) { _shape = shape; };
		BBType GetShape() { return _shape; };

	protected:
		BBType _shape;
		bool _isTrigger;
		std::shared_ptr<RigidBody> _rb;
		std::function<void(std::shared_ptr<Entity>&)> _trigger;
	};
}

#endif // __GAME_COLLIDERCOMPONENT