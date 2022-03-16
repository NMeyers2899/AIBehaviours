#include "Enemy.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "StateMachineComponent.h"
#include "IsAggressiveDecision.h"
#include "SeekDecision.h"
#include "WanderDecision.h"
#include "IdleDecision.h"
#include "InRangeDecision.h"
#include "DecisionComponent.h"

Enemy::Enemy(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) : Agent(x, y, name, maxForce, maxSpeed, target)
{
	m_target = target;
}
void Enemy::start()
{
	Agent::start();

	IdleDecision* idle = new IdleDecision();
	WanderDecision* wander = new WanderDecision();
	SeekDecision* seek = new SeekDecision();

	IsAggressiveDecision* aggressive = new IsAggressiveDecision(idle, wander);
	InRangeDecision* inRange = new InRangeDecision(aggressive, seek);

	addComponent(new DecisionComponent(inRange));

	// Adding the sprite component.
	getTransform()->setScale({ 50,50 });
	addComponent(new SpriteComponent("SpriteComponent", "Images/enemy.png"));

	// Adding the wander behavior.
	WanderBehavior* comp = new WanderBehavior(1000, 100, 100);
	addComponent(comp);

	// Adding the seek behavior.
	SeekBehavior* seekBehavior = new SeekBehavior();
	seekBehavior->setSteeringForce(50);
	seekBehavior->setTarget(m_target);
	addComponent(seekBehavior);
}

bool Enemy::getTargetInSight()
{
	float distance = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	MathLibrary::Vector2 direction = (m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized();
	return distance <= 300 && acos(MathLibrary::Vector2::dotProduct(direction, getTransform()->getForward())) < 1;
}
