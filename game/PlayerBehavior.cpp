#include "PlayerBehavior.h"

game::PlayerBehavior::PlayerBehavior() : Behavior(typeid(PlayerBehavior).name())
{

}

game::PlayerBehavior::~PlayerBehavior()
{

}

void game::PlayerBehavior::Start()
{
	_rigidBody = std::dynamic_pointer_cast<RigidBody>(_parent->GetComponent(typeid(RigidBody).name()));
}

void game::PlayerBehavior::Update(float dt)
{
	sf::Vector2<float> f;
	float force = 10000.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		f.y = -force;
		_rigidBody->AddImpulseForce(f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		f.y = force;
		_rigidBody->AddImpulseForce(f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		f.x = -force;
		_rigidBody->AddImpulseForce(f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		f.x = force;
		_rigidBody->AddImpulseForce(f);
	}
}