#include "FleeBehavior.h"
#include "MoveComponent.h"
#include "Actor.h"

FleeBehaviour::FleeBehaviour(float force)
{
	m_force = force;
}

MathLibrary::Vector2 FleeBehaviour::calculateForce()
{
	return MathLibrary::Vector2();
}
