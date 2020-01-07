#include "GameScene.h"
#include "GraphFactory.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "Vector2D.h"
#include "Keyfrem.h"
#include "WindowInfo.h"
#include "number.h"
#include <iterator>
#include <string>

GameScene::GameScene()
{
	
}

void GameScene::Initialize()
{
	_gameImage = GraphFactory::Instance().LoadGraph("img\\pipo-battlebg001b.jpg");
	player = new Player(Vector2D(240, 500));
	playershot = new PlayerShot;
	keyfrem = new Keyfrem;
	manager = new EnemyManager();
	collision = new Collision();
	pulseManager = new PulseManager();
	player->Start();
	manager->Start();
}

void GameScene::Update()
{
	DrawGraph(0, 0, _gameImage, FALSE);
	keyfrem->gadUpdateKey();
	
	if (keyfrem->Key[KEY_INPUT_SPACE] == 1||player->hp <0) {
		//	ゲームシーンに移りたいが、どのようにシーンを変更するか？
		SceneManager::Instance().LoadScene("Clear");
	}
	manager->Update();
	player->Update();
	playershot->Update();
	static int angle;
	
		if (player->OnShotButton() == 1) {
			if (CheckHitKey(KEY_INPUT_LSHIFT))
				playershot->Shot(player->Position(), -135);
			else if (CheckHitKey(KEY_INPUT_Z))
				playershot->Shot(player->Position(), -45);
			else
				playershot->Shot(player->Position(), -90);
		}
	
	pulseManager->Update();
	
	for (auto it = pulseManager->_pDeviceList.begin(); it != pulseManager->_pDeviceList.end();)
	{
		if ((*it)->hitFlag)
			continue;
		for (auto it2 = playershot->_shotList.begin(); it2 != playershot->_shotList.end();) 
		{
			if (collision->CircleCollision((*it)->GetPos(), 16, (*it2)->Position(), 16))
			{
				(*it)->hitFlag = true;
			}
			++it2;
			
		}
		
		
		for (auto it3 = pulseManager->_pulseList.begin(); it3 != pulseManager->_pulseList.end();)
		{
			if (collision->CircleCollision((*it)->GetPos(), 16, (*it3)->GetPos(), (*it3)->GetNowSize()))
			{
				(*it)->hitFlag = true;
			}
			++it3;
		}
		++it;
	}
	
	manager->Render();
	player->Render();
	playershot->Render();
	pulseManager->Render();
	Hit();
}

void GameScene::Hit()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (collision->CircleCollision(manager->data[i].pos, 16, player->Position(), 16))
		{
			DrawString(0, 0, "当たった！", GetColor(255, 0, 0));
			manager->data[i].hp--;
			player->hp--;
		}
	}
	for (auto it2 = playershot->_shotList.begin(); it2 != playershot->_shotList.end();)
	{
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			if (collision->CircleCollision(manager->data[i].pos, 16, (*it2)->Position(), 16))
			{
				DrawString(0, 0, "当たった！", GetColor(255, 0, 0));
				manager->data[i].hp--;
			}
		}
		++it2;
	}
	for (auto it3 = pulseManager->_pulseList.begin(); it3 != pulseManager->_pulseList.end();)
	{
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			if (collision->CircleCollision(manager->data[i].pos, 16, (*it3)->GetPos(), (*it3)->GetNowSize()))
			{
				DrawString(0, 0, "当たった！", GetColor(255, 0, 0));
				manager->data[i].hp--;
			}
		}
		++it3;
	}
}

void GameScene::Release()
{
	GraphFactory::Instance().EraseGraph("img\\pipo-battlebg001b.jpg");
	//delete manager;
}
