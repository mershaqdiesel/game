#include "Entity.h"
#include "Component.h"

game::Entity::Entity() : transform(), _parent(nullptr), _children(), _components()
{

}

game::Entity::Entity(std::string tag) : _tag(tag), transform(), _parent(nullptr), _children(), _components()
{

}

game::Entity::~Entity()
{

}

std::shared_ptr<game::Component> game::Entity::GetComponent(std::string name)
{
	for (auto comp : _components)
	{
		if (comp->GetType().compare(name) == 0)
		{
			return comp;
		}
	}
	return nullptr;
}

bool game::Entity::AddComponent(std::shared_ptr<game::Component> comp)
{
	// there should only be one type of component per entity
	auto c = GetComponent(comp->GetType());
	if (c == nullptr)
	{
		_components.push_back(comp);
		return true;
	}
	return false;
}

sf::Transform game::Entity::CalcTransform()
{
	if (_parent == nullptr)	// we have no parent
	{
		return transform.getTransform();
	}
	return (transform.getTransform() * _parent->CalcTransform());
}