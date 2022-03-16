#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include <Vector2.h>

class SteeringComponent;
class FleeBehaviour;
class SeekBehaviour;
class WanderBehaviour;
class MoveComponent;
class SpriteComponent;

class Agent : public Actor
{
public:
	Agent(float x, float y, const char* name, float maxForce, float maxSpeed, Actor* target);
	void start() override;
	void update(float deltaTime) override;
	void onAddComponent(Component* comp) override;

	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float value) { m_maxForce = value; }
	MathLibrary::Vector2 getForce() { return m_force; }
	void setForce(MathLibrary::Vector2 value) { m_force = value; }

	MoveComponent* getMoveComponent() { return m_moveComponent; }

	void setTarget(Actor* value);

private:
	DynamicArray<SteeringComponent*> m_steeringComponents;
	float m_maxForce;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	MathLibrary::Vector2 m_force;
};

