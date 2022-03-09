#include "StateMachineComponent.h"
#include "Actor.h"
#include "Transform2D.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"

void StateMachineComponent::start()
{
	Component::start();

	m_seekBehavior = getOwner()->getComponent<SeekBehavior>();
	m_seekForce = m_seekBehavior->getSteeringForce();

	m_wanderBehavior = getOwner()->getComponent<WanderBehavior>();
	m_wanderForce = m_wanderBehavior->getSteeringForce();

	m_currentState = IDLE;
}

void StateMachineComponent::update(float deltaTime)
{
	MathLibrary::Vector2 targetPos = m_seekBehavior->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();

	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;

	switch (m_currentState)
	{
	case IDLE:
		m_seekBehavior->setSteeringForce(0);
		m_wanderBehavior->setSteeringForce(0);

		if (targetInRange)
			setCurrentState(SEEK);
		break;
	case WANDER:
		m_seekBehavior->setSteeringForce(0);
		m_wanderBehavior->setSteeringForce(m_wanderForce);

		if (targetInRange)
			setCurrentState(SEEK);
		break;
	case SEEK:
		m_seekBehavior->setSteeringForce(m_seekForce);
		m_wanderBehavior->setSteeringForce(0);

		if (!targetInRange)
			setCurrentState(WANDER);
		break;
	}
}
