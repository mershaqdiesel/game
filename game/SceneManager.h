#ifndef __GAME_SCENEMANAGER
#define __GAME_SCENEMANAGER

#include <iostream>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Scene.h"

namespace game
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		void Push(std::shared_ptr<Scene> s);
		std::shared_ptr<Scene> Top();
		std::shared_ptr<Scene> Pop();

		int Run();

	private:
		bool _isRunning;
		int _frameRate;
		std::vector<std::shared_ptr<Scene> > _scenes;

		sf::RenderWindow _window;
	};
}

#endif // __GAME_SCENEMANAGER