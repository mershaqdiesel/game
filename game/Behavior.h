#ifndef __GAME_BEHAVIOR
#define __GAME_BEHAVIOR

#include <functional>
#include <string>

#include <SFML/Window/Event.hpp>

#include "Component.h"

namespace game
{
	class Behavior : public Component
	{
	public:
		Behavior(const std::string& t) : Component(t) {};
		virtual ~Behavior() {};
		virtual void Start() {}
		virtual void Update(float deltaTime) {};
	};
}

#endif // __GAME_BEHAVIOR