#include "TestScene.h"
#include "Player.h"
#include "Transform2D.h"
void TestScene::start()
{
	//c3 - base.Start()
	Scene::start();

	Player* player = new Player();
	MathLibrary::Vector2 scale = MathLibrary::Vector2(50, 50);
	player->getTransform()->setScale(MathLibrary::Vector2(50, 50));
	addActor(player);
}
