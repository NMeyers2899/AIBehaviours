#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "MainScene.h"
#include "Player.h"
#include "Agent.h"
#include "SeekBehavior.h"
#include "WanderBehavior.h"
#include "StateMachineComponent.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });

	Agent* agent1 = new Agent();
	agent1->getTransform()->setScale({ 50,50 });
	agent1->setMaxForce(200);
	agent1->addComponent(new SpriteComponent("SpriteBoi", "Images/enemy.png"));

	WanderBehavior* comp = new WanderBehavior(1000, 200, 100);
	agent1->addComponent(comp);

	SeekBehavior* seekBehavior = new SeekBehavior();
	seekBehavior->setSteeringForce(50);
	seekBehavior->setTarget(player);
	agent1->addComponent(seekBehavior);
	agent1->addComponent<StateMachineComponent>();

	addActor(player);
	addActor(agent1);
}
