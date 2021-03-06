#include "Agent.h"
#include "FleeBehavior.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "SteeringComponent.h"

Agent::Agent(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target) : Actor(x, y, name)
{
	setMaxForce(maxForce);

	m_moveComponent = addComponent<MoveComponent>();
	m_moveComponent->setMaxSpeed(maxSpeed);
}

void Agent::start()
{
	Actor::start();

	m_moveComponent->setUpdateFacing(true);
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);

	// Get all force beind applied from steering behaviors.
	for (int i = 0; i < m_steeringComponents.getLength(); i++)
		m_force = m_force + m_steeringComponents[i]->calculateForce();

	// Clamp force if it exceeds the maximum scale.
	if (m_force.getMagnitude() > getMaxForce())
		m_force = m_force.getNormalized() * getMaxForce();

	// Apply force to velocity.
	getMoveComponent()->setVelocity(getMoveComponent()->getVelocity() + m_force * deltaTime);
}

void Agent::onAddComponent(Component* comp)
{ 
	SteeringComponent* steeringComponent = dynamic_cast<SteeringComponent*>(comp);
	if (steeringComponent)
		m_steeringComponents.addItem(steeringComponent);
}
