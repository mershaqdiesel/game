#ifndef __GAME_CAMERA
#define __GAME_CAMERA

#include <SFML/Graphics/View.hpp>

#include "Component.h"

namespace game
{
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		sf::View GetView();

	private:
		sf::View _view;
	};
}

#endif // __GAME_CAMERA