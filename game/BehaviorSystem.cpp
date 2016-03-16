#include "BehaviorSystem.h"

game::BehaviorSystem::BehaviorSystem()
{

}

game::BehaviorSystem::~BehaviorSystem()
{

}

void game::BehaviorSystem::Start()
{
	for (auto behavior : _behaviors)
	{
		behavior->Start();
	}
}

void game::BehaviorSystem::UpdateAll(float deltaTime)
{
	for (auto behavior : _behaviors)
	{
		behavior->Update(deltaTime);
	}
}

// creates a behavior from a given updater function
void game::BehaviorSystem::AddBehavior(
	std::shared_ptr<Behavior> behavior,
	std::shared_ptr<Entity> _parent)
{
	if (_parent->AddComponent(behavior))
	{
		behavior->SetParent(_parent);
		_behaviors.push_back(behavior);
	}
}