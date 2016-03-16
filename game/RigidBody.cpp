#include "RigidBody.h"

float game::RigidBody::EPSILON = std::numeric_limits<float>::epsilon();

game::RigidBody::RigidBody() : PhysicsComponent(typeid(RigidBody).name()), _acceleration(0.f, 0.f), _velocity(0.f, 0.f), _forceAccum(0.0f, 0.0f)
{
	_friction = 1.0f;
	_invMass = 1.0f;
	_damping = 0.2f;
}

game::RigidBody::~RigidBody()
{

}

void game::RigidBody::SetMass(float mass)
{
	assert(mass != 0.0f);
	_invMass = 1.0f / mass;
}

void game::RigidBody::SetDamping(float damp)
{
	_damping = damp;
}

void game::RigidBody::SetFriction(float friction)
{
	_friction = friction;
}

sf::Vector2f game::RigidBody::GetVelocity() const
{
	return _velocity;
}

sf::Vector2f game::RigidBody::GetAcceleration() const
{
	return _acceleration;
}

float game::RigidBody::GetInvMass() const
{
	return _invMass;
};

void game::RigidBody::Update(float dt)
{
	sf::Vector2f oldAcceleration = _acceleration;
	sf::Vector2f oldVelocity = _velocity;

	// update position
	_parent->transform.move(_velocity * dt + (0.5f * oldAcceleration * (dt * dt)));
	
	// cacluate new acceleration
	_acceleration = _forceAccum * _invMass;
	_forceAccum.x = _forceAccum.y = 0.0f;

	// avoid floating point errors
	if (_acceleration.x < EPSILON && _acceleration.x > -EPSILON)
	{
		_acceleration.x = 0.0f;
	}
	if (_acceleration.y < EPSILON && _acceleration.y > -EPSILON)
	{
		_acceleration.y = 0.0f;
	}

	// calculate new velocity
	_velocity += (((oldAcceleration + _acceleration) / 2.0f) * dt);
	_velocity *= pow(_damping, dt);

	//std::cout << "velocity (" << _velocity.x << ", " << _velocity.y << ")\t" 
	//	<< "acceleration (" << _acceleration.x << ", " << _acceleration.y << ")" << std::endl;
}

void game::RigidBody::AddImpulseForce(const sf::Vector2<float>& force)
{
	_forceAccum += force;
}