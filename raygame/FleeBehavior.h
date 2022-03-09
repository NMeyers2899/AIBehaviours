#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>

class FleeBehaviour : public SteeringComponent
{
public:
	FleeBehaviour(float force);

	MathLibrary::Vector2 calculateForce() override;

private:
	float m_force;
};

