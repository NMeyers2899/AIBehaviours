#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "MainScene.h"
#include "Player.h"
#include "Enemy.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });

	Enemy* enemy1 = new Enemy(500, 500, "Enemy1", 200, 200, player);

	addActor(player);
	addActor(enemy1);
}
