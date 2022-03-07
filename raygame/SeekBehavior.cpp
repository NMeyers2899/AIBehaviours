#include "SeekBehavior.h"
#include "MoveComponent.h"
#include "Actor.h"
#include "Transform2D.h"

MathLibrary::Vector2 SeekBehaviour::calculateForce()
{
	if (getOwner() && getTarget())
	{
		MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition() - getTarget()->getTransform()->getWorldPosition();

		MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
		MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

		return seekForce;
	}

	return { 0, 0 };
}
