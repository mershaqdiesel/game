#include "CollisionUtil.h"

bool game::CollisionUtil::CollidesWith(std::shared_ptr<ColliderComponent>& a, std::shared_ptr<ColliderComponent>& b)
{
	bool didCollide = false;
	if (a->_shape == BBType::Circle && b->_shape == BBType::Circle)
	{
		didCollide = CircleOnCircle(std::dynamic_pointer_cast<CircleCollider>(a), std::dynamic_pointer_cast<CircleCollider>(b));
	}
	if (a->_shape == BBType::AABB && b->_shape == BBType::AABB)
	{
		didCollide = AABBOnAABB(std::dynamic_pointer_cast<AABBCollider>(a), std::dynamic_pointer_cast<AABBCollider>(b));
	}
	return didCollide;
}

void game::CollisionUtil::Resolve(std::shared_ptr<ColliderComponent>& a, std::shared_ptr<ColliderComponent>& b)
{
	std::cout << "Collided!" << std::endl;
	// get the relative velocity
	sf::Vector2f relativeVel = b->_rb->GetVelocity() - a->_rb->GetVelocity();

	// calculate the impact angle / normal
	sf::Vector2f normal = b->_parent->transform.getPosition() - a->_parent->transform.getPosition();

	float scale = relativeVel.x * normal.x + relativeVel.y * normal.y;

	if (scale >= 0)
	{
		return;
	}

	scale *= -1;
	scale /= a->_rb->GetInvMass() + b->_rb->GetInvMass();

	sf::Vector2f impulse = scale * normal;
	a->_rb->AddImpulseForce(-impulse);
	b->_rb->AddImpulseForce(impulse);
}

bool game::CollisionUtil::CircleOnCircle(std::shared_ptr<CircleCollider>& a, std::shared_ptr<CircleCollider>& b)
{
	float r = a->GetRadius() + b->GetRadius();
	r *= r;
	sf::Vector2f dist = (b->_parent->transform.getPosition() - a->_parent->transform.getPosition());
	return r > ((dist.x * dist.x) + (dist.y * dist.y));
}

bool game::CollisionUtil::AABBOnAABB(std::shared_ptr<AABBCollider>& a, std::shared_ptr<AABBCollider>& b)
{
	bool collided = false;
	// TODO: [pmd] use separating axis theorem
	return collided;
}