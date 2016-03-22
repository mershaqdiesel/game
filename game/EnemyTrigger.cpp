#include "EnemyTrigger.h"

void game::EnemyTrigger::OnCollision(std::shared_ptr<Entity>& left, std::shared_ptr<Entity>& right)
{
	std::shared_ptr<CircleCollider> leftCc = std::dynamic_pointer_cast<CircleCollider> (left->GetComponent(typeid(CircleCollider).name()));
	std::shared_ptr<CircleGraphic> leftCg = std::dynamic_pointer_cast<CircleGraphic> (left->GetComponent(typeid(CircleGraphic).name()));

	std::shared_ptr<CircleCollider> rightCc = std::dynamic_pointer_cast<CircleCollider> (right->GetComponent(typeid(CircleCollider).name()));
	std::shared_ptr<CircleGraphic> rightCg = std::dynamic_pointer_cast<CircleGraphic> (right->GetComponent(typeid(CircleGraphic).name()));

	// get overlap (NOT THE ACTUAL RADII)
	float leftRad = leftCc->GetRadius();
	float rightRad = rightCc->GetRadius();
	
	sf::Vector2f overlapVec = (right->transform.getPosition() - left->transform.getPosition());
	float overlapLen = sqrt(overlapVec.x * overlapVec.x + overlapVec.y + overlapVec.y);

	float newLeftRad = 0.f, newRightRad = 0.f;
	if (leftRad >= rightRad)
	{
		newLeftRad = leftRad + overlapLen;
		newRightRad = rightRad - overlapLen;
	}
	else
	{
		newLeftRad = leftRad - overlapLen;
		newRightRad = rightRad + overlapLen;
	}

	// destroy objects if they are less than 0 radius
	if (newLeftRad <= 0.0f)
	{
		// destroy left
	}
	else
	{
		leftCc->SetRadius(newLeftRad);
		leftCg->SetSize(newLeftRad);
	}

	if (newRightRad <= 0.0f)
	{
		// destroy right
	}
	else
	{
		rightCc->SetRadius(newRightRad);
		rightCg->SetSize(newRightRad);
	}
}