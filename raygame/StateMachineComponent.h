#pragma once
#include "Component.h"

enum State 
{
	IDLE,
	WANDER,
	SEEK
};

class SeekBehavior;
class WanderBehavior;

class StateMachineComponent : public Component
{
public:
	void start() override;

	State getCurrentState() { return m_currentState; }
	void setCurrentState(State value) { m_currentState = value; }

	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekBehavior* m_seekBehavior;
	WanderBehavior* m_wanderBehavior;
	float m_seekForce;
	float m_wanderForce;
	float m_seekRange = 100;
};

