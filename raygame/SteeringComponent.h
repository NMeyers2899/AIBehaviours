#pragma once
#include "Component.h"
#include <Vector2.h>

class SteeringComponent : public Component
{
public:
	SteeringComponent(Actor* target) { m_target = target; }

	void update(float deltaTime) override;

	float calculateForce();

private:
	MathLibrary::Vector2 m_force;
	Actor* m_target;
};

