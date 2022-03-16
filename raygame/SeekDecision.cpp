#include "SeekDecision.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "Agent.h"
#include "Enemy.h"

void SeekDecision::makeDecision(Agent* agent, float deltaTime)
{
	SeekBehavior* seek = agent->getComponent<SeekBehavior>();
	WanderBehavior* wander = agent->getComponent<WanderBehavior>();
	Enemy* enemy = dynamic_cast<Enemy*>(agent);
	if (seek)
		seek->setSteeringForce(52);
	if (enemy)
		enemy->setIsAggressive(true);
	if (wander)
		wander->setSteeringForce(0);
}
