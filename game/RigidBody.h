#ifndef __GAME_RIGIDBODY
#define __GAME_RIGIDBODY

#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

#include <SFML\System\Vector2.hpp>

#include "PhysicsComponent.h"

namespace game
{
	class RigidBody : public PhysicsComponent
	{
	public:
		RigidBody();
		~RigidBody();

		void Update(float dt);
		void AddImpulseForce(const sf::Vector2<float>& force);

		void SetMass(float mass);
		void SetFriction(float friction);
		void SetDamping(float damp);

		sf::Vector2f GetVelocity() const;
		sf::Vector2f GetAcceleration() const;
		float GetInvMass() const;

	private:
		sf::Vector2f _acceleration;
		sf::Vector2f _velocity;

		sf::Vector2f _forceAccum;

		float _friction;
		float _invMass;
		float _damping;

		static float EPSILON;
	};
}

#endif // __GAME_RIGIDBODY