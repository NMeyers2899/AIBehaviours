#include "InRangeDecision.h"
#include "Enemy.h"

bool InRangeDecision::checkCondition(Agent* owner, float deltaTime)
{
	Enemy* enemy = dynamic_cast<Enemy*>(owner);

	if (enemy)
		return enemy->getTargetInSight();

	return false;
}
