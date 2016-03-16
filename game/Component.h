#ifndef __GAME_COMPONENT
#define __GAME_COMPONENT

#include <memory>
#include <string>

#include "Entity.h"

namespace game
{
	class Component
	{
	public:
		Component(std::string t) { SetType(t); };
		virtual ~Component()=0;

		std::string GetType() { return _type; };
		void SetType(std::string n) { _type = n; };

		void SetParent(std::shared_ptr<Entity> parent) { _parent = parent; };

	protected:
		std::string _type;					// type of component
		std::shared_ptr<Entity> _parent;	// owner of the component
	};
}

#endif // __GAME_COMPONENT