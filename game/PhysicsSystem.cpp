#include "PhysicsSystem.h"

game::PhysicsSystem::PhysicsSystem() : _rigidBodies()
{

}

game::PhysicsSystem::~PhysicsSystem()
{

}

void game::PhysicsSystem::Update(float time)
{
	// detect and resolve collisions
	for (unsigned int i = 0; i < _colliders.size(); ++i)
	{
		for (unsigned int j = i + 1; j < _colliders.size(); ++j)
		{
			// detected a collision
			if (CollisionUtil::CollidesWith(_colliders[i], _colliders[j]))
			{
				// check for triggers first, activate those if any, otherwise resolve normal collision
				if (_colliders[i]->IsTrigger())
				{
					_colliders[i]->OnTrigger(_colliders[j]->_parent);
				}
				else if (_colliders[j]->IsTrigger())
				{
					_colliders[j]->OnTrigger(_colliders[i]->_parent);
				}
				else
				{
					CollisionUtil::Resolve(_colliders[i], _colliders[j]);
				}
			}
		}
	}

	// update the velocity and acceleration
	for (auto body : _rigidBodies)
	{
		body->Update(time);
	}
}

std::shared_ptr<game::PhysicsComponent> game::PhysicsSystem::Create(std::string type, std::shared_ptr<Entity> parent)
{
	if (type.compare(typeid(RigidBody).name()) == 0)
	{
		std::shared_ptr<PhysicsComponent> rb(new RigidBody());
		if (parent->AddComponent(rb))
		{
			rb->SetParent(parent);
			_rigidBodies.push_back(std::dynamic_pointer_cast<RigidBody>(rb));
			return rb;
		}
	}
	if (type.compare(typeid(CircleCollider).name()) == 0)
	{
		std::shared_ptr<RigidBody> body = std::dynamic_pointer_cast<RigidBody> (parent->GetComponent(typeid(RigidBody).name()));
		std::shared_ptr<ColliderComponent> cc;
		// require the entity to have a rigidbody
		if (body != nullptr)
		{
			cc = std::shared_ptr<ColliderComponent>(new CircleCollider(body));
			if (parent->AddComponent(cc))
			{
				cc->SetParent(parent);
				cc->SetShape(BBType::Circle);
				_colliders.push_back(std::dynamic_pointer_cast<ColliderComponent>(cc));
				return cc;
			}
		}
	}
	return nullptr;
}