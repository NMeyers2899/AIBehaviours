#include "IdleDecision.h"
#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "Agent.h"

void IdleDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();

	if (wander)
		wander->setSteeringForce(0);

	SeekBehavior* seek = agent->getComponent<SeekBehavior>();

	if (seek)
		seek->setSteeringForce(0);
}
