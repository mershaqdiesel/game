#ifndef __GAME_ENEMYTRIGGER
#define __GAME_ENEMYTRIGGER

#include <memory>

#include "Entity.h"
#include "CircleCollider.h"
#include "CircleGraphic.h"

namespace game
{
	class EnemyTrigger
	{
	public:
		static void OnCollision(std::shared_ptr<Entity>& left, std::shared_ptr<Entity>& right);
	};
}

#endif