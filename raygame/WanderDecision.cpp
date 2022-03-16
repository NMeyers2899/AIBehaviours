#include "WanderDecision.h"
#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "Agent.h"

void WanderDecision::makeDecision(Agent* agent, float deltaTime)
{
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	SeekBehavior* seek = agent->getComponent<SeekBehavior>();

	if (wander)
		wander->setSteeringForce(52);

	if (seek)
		seek->setSteeringForce(0);
}
