#include "Scene.h"

#include "CircleGraphic.h"
#include "PlayerBehavior.h"
#include "EnemyTrigger.h"

int game::Scene::_numTotalScenes = 0;

game::Scene::Scene() : _entities(), _graphics(), _behaviors()
{
	_numTotalScenes++;

	// set up player
	std::shared_ptr<Entity> player(new Entity("Player"));
	player->transform.move(-50.f, 0.f);

	std::shared_ptr<PlayerBehavior> pb(new PlayerBehavior());
	_behaviors.AddBehavior(pb, player);

	std::shared_ptr<CircleGraphic> cg = std::dynamic_pointer_cast<CircleGraphic>(_graphics.Create(typeid(CircleGraphic).name(), player));
	cg->SetSize(10.f);
	cg->SetColor(sf::Color::Green);

	std::shared_ptr<RigidBody> rb = std::dynamic_pointer_cast<RigidBody>(_physics.Create(typeid(RigidBody).name(), player));
	rb->SetMass(5.0f);
	rb->SetFriction(0.1f);

	std::shared_ptr<CircleCollider> cc = std::dynamic_pointer_cast<CircleCollider>(_physics.Create(typeid(CircleCollider).name(), player));
	cc->SetTrigger(EnemyTrigger::OnCollision);

	// set up enemy
	std::shared_ptr<Entity> enemy(new Entity("Enemy"));
	enemy->transform.move(50.f, 0.f);

	std::shared_ptr<CircleGraphic> enemyCircle = std::dynamic_pointer_cast<CircleGraphic>(_graphics.Create(typeid(CircleGraphic).name(), enemy));
	enemyCircle->SetSize(10.f);
	enemyCircle->SetColor(sf::Color::Red);

	std::shared_ptr<RigidBody> enemyBody = std::dynamic_pointer_cast<RigidBody>(_physics.Create(typeid(RigidBody).name(), enemy));
	enemyBody->SetMass(5.0f);
	enemyBody->SetFriction(0.1f);

	std::shared_ptr<CircleCollider> enemyCollider = std::dynamic_pointer_cast<CircleCollider>(_physics.Create(typeid(CircleCollider).name(), enemy));
	enemyCollider->SetTrigger(EnemyTrigger::OnCollision);

	// add tracking for entities
	_entities.push_back(player);
	_entities.push_back(enemy);
}

game::Scene::Scene(std::string fname)
{
	_numTotalScenes++;
	Load(fname);
}

game::Scene::~Scene()
{
	_numTotalScenes--;
}

void game::Scene::Load(std::string fname)
{

}

void game::Scene::Init()
{
	_behaviors.Start();
}

void game::Scene::Update(float secs)
{
	_behaviors.UpdateAll(secs);
}

void game::Scene::PhysicsUpdate(float secs)
{
	_physics.Update(secs);
}

void game::Scene::Draw(sf::RenderTarget& target)
{
	_graphics.Render(target);
}

void game::Scene::HandleInput(sf::Event& event)
{

}