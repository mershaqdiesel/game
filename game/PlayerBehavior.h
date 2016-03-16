#ifndef __GAME_PLAYERBEHAVIOR
#define __GAME_PLAYERBEHAVIOR

#include <iostream>

#include <SFML\Window\Keyboard.hpp>

#include "Behavior.h"
#include "RigidBody.h"

namespace game
{
	class PlayerBehavior : public Behavior
	{
	public:
		PlayerBehavior();
		~PlayerBehavior();

		void Start();
		void Update(float dt);

	private:
		std::shared_ptr<RigidBody> _rigidBody;
	};
}

#endif