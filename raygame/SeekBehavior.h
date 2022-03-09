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
	float m_force;
};

