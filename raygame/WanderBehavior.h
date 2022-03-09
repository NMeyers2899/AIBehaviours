#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>

class WanderBehavior : public SteeringComponent
{
public:
	WanderBehavior(float distance, float radius, float force);

	MathLibrary::Vector2 calculateForce() override;

private:
	float m_force;
	float m_radius;
	float m_circleDistance = 0;

	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_circlePosition;
};

