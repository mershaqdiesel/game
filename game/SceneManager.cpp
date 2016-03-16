#include "SceneManager.h"

game::SceneManager::SceneManager() : _scenes(), _window()
{
	_isRunning = true;
	_frameRate = 60;
	_window.create(sf::VideoMode(800, 600), "game");
	_window.setFramerateLimit(_frameRate);
}

game::SceneManager::~SceneManager()
{
}

void game::SceneManager::Push(std::shared_ptr<Scene> s)
{
	_scenes.push_back(s);
}

std::shared_ptr<game::Scene> game::SceneManager::Top()
{
	if (_scenes.size() < 1)
	{
		return std::shared_ptr<Scene>(nullptr);
	}
	return _scenes[_scenes.size() - 1];
}

std::shared_ptr<game::Scene> game::SceneManager::Pop()
{
	std::shared_ptr<game::Scene> s = this->Top();

	_scenes.pop_back();

	return s;
}

int game::SceneManager::Run()
{
	sf::Clock clock;
	clock.restart();

	float  current = 0.f, dt = 0.f;
	float prev = clock.getElapsedTime().asSeconds();

	std::shared_ptr<game::Scene> currentScene;

	currentScene = Top();
	currentScene->Init();

	// main game loop
	while (_isRunning)
	{
		// get time and calculate elapsed time
		current = clock.getElapsedTime().asSeconds();
		dt = current - prev;

		//std::cout << dt << std::endl;

		// process events
		sf::Event e;

		while (_window.pollEvent(e))
		{
			float x = 0.f, y = 0.f;

			// close the window if necessary
			if ((e.type == sf::Event::Closed) || 
				(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape))
			{
				_isRunning = false;
			}

			currentScene->HandleInput(e);
		}
		
		// run the physics updates
		currentScene->PhysicsUpdate(dt);

		// run the game logic per scene
		currentScene->Update(dt);

		// clear the buffer
		_window.clear(sf::Color::Black);

		// draw objects
		currentScene->Draw(_window);

		// show the window
		_window.display();

		// record the end time for the next frame
		prev = current;
	}

	_window.close();

	return 0;
}