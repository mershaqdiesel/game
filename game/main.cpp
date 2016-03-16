#include "SceneManager.h"

#include "Scene.h"

// entry point into the program
int main(int argc, char* argv[])
{
	game::SceneManager sceneManager;

	std::shared_ptr<game::Scene> b = std::make_shared<game::Scene>();

	sceneManager.Push(b);

	return sceneManager.Run();
}