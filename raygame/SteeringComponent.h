#pragma once
#include "Component.h"
#include <Vector2.h>
#include "Agent.h"

class SteeringComponent : public Component
{
public:
	SteeringComponent() { m_target = nullptr; }
	SteeringComponent(Actor* target, float steeringForce) { m_target = target; m_steeringForce = steeringForce; }

	void start() override;
	void update(float deltaTime) override;

	virtual MathLibrary::Vector2 calculateForce() = 0;

	float getSteeringForce() { return m_steeringForce; }
	void setSteeringForce(float value) { m_steeringForce = value; }
	Actor* getTarget() { return m_target; }
	void setTarget(Actor* target) { m_target = target; }

	Agent* getAgent() { return (Agent*)getOwner(); }
	

private:
	float m_steeringForce;
	Actor* m_target;
};

