#pragma once
#include "SteeringComponent.h"

class MoveComponent;
class Actor;

class SeekBehaviour : public SteeringComponent
{
public:
	void start() override;

	MathLibrary::Vector2 calculateForce() override;

private:
	Actor* m_target;
	MoveComponent* m_moveComponent;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_steeringForce;
	MathLibrary::Vector2 m_currentVelocity;
	float m_force;
};

