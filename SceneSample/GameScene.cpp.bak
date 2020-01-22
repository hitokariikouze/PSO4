#include "GameScene.h"
#include "GraphFactory.h"
#include "DxLib.h"
#include "SceneManager.h"
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
	//_gameImage = GraphFactory::Instance().LoadGraph("img\\pipo-battlebg001b.jpg");
	player = new Player(Vector2D(240, 500));
	playershot = new PlayerShot;
	enemyshot = new EnemyShot;
	keyfrem = new Keyfrem;
	manager = new EnemyManager();
	collision = new Collision();
	pulseManager = new PulseManager();
	player->Start();
	manager->Start();
	if (num == 0)
	{
		manager->Stage1();
		boss = new Boss(Vector2D(200, -100), 0);
	}
	if (num == 1)
	{
		manager->Stage2();
		boss = new Boss(Vector2D(200, -120), 1);
	}
	boss->Start();

	colpos.x = 16;
	colpos.y = 16;
	pos.x = 48;
	pos.y = 48;
	damageSE = LoadSoundMem("sound\\damage01.mp3");
	pulseSE = LoadSoundMem("sound\\pulse01.mp3");
	pulseSE2 = LoadSoundMem("sound\\pulse03.mp3");
	pulseSE3 = LoadSoundMem("sound\\pulse04.mp3");
	playBGM = LoadSoundMem("sound\\playBGM.mp3");
	PlaySoundMem(playBGM, DX_PLAYTYPE_LOOP);

	destroyCount = 0;
}

void GameScene::Update()
{
	DrawBox(0, 0, WindowInfo::WindowWidth, WindowInfo::WindowHeight, GetColor(0, 0, 0), TRUE);
	if (timer < 10)
		timer++;
	else {
		StarDot* starDot = new StarDot(Vector2D(12 + GetRand(WindowInfo::WindowWidth - 12), 0));
		starDotList.push_back(starDot);
		timer = 0;
	}
	DrawGraph(0, 0, _gameImage, FALSE);
	keyfrem->gadUpdateKey();
	if (keyfrem->Key[KEY_INPUT_SPACE] == 1 || boss->hp <= 0) {
		//	ゲームシーンに移りたいが、どのようにシーンを変更するか？
		num++;
		if (num >= 3)
			SceneManager::Instance().LoadScene("Clear");
		else
			SceneManager::Instance().LoadScene("Game");
	}
	else if (player->hp <= 0) {
		SceneManager::Instance().LoadScene("Title");
	}
	for (auto it = starDotList.begin(); it != starDotList.end();)
	{
		(*it)->Update();
		it++;
	}
	manager->Update();
	if (manager->bossflag) {
		boss->Update();
	}
	player->Update();
	playershot->Update();
	enemyshot->Update();

	if (player->OnShotButton() == 1 && playershot->shotflag == false)
	{
		playershot->shotflag = true;
		if (CheckHitKey(KEY_INPUT_Z))
			playershot->Shot(player->Position(), 90);
		else
			playershot->Shot(player->Position(), -90);
	}
	EnemyAttack();
	BossAttack();
	pulseManager->Update();
	Pulse();
	for (auto it = starDotList.begin(); it != starDotList.end();)
	{
		(*it)->Render();
		it++;
	}
	manager->Render();
	player->Render();
	boss->Render();
	playershot->Render();
	enemyshot->Render();
	pulseManager->Render();
	Hit();
}

void GameScene::Hit()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (collision->CircleCollider(manager->data[i].pos, 16, player->Position(), player->Size().x / 4) && player->hitflag == false)
		{
			PlaySoundMem(damageSE, DX_PLAYTYPE_BACK);
			manager->data[i].hp--;
			player->hp--;
			player->hitflag = true;
		}
	}
	for (auto it = playershot->_shotList.begin(); it != playershot->_shotList.end();)
	{
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			if (collision->CircleCollider(manager->data[i].pos, 16, (*it)->Position(), 16))
			{
				PlaySoundMem(damageSE, DX_PLAYTYPE_BACK);
				manager->data[i].hp -= player->GetShotDamage();
			}
		}
		++it;
	}
	for (auto it = pulseManager->_pulseList.begin(); it != pulseManager->_pulseList.end();)
	{
		for (int i = 0; i < ENEMY_NUM; i++)
		{
			if (collision->CircleCollider(manager->data[i].pos, 16, (*it)->GetPos() - colpos, (*it)->GetNowSize()))
			{
				PlaySoundMem(damageSE, DX_PLAYTYPE_BACK);
				manager->data[i].hp--;
			}
		}
		++it;
	}
	for (auto it = enemyshot->_shotList.begin(); it != enemyshot->_shotList.end();)
	{
		if (collision->CircleCollider(player->Position(), player->Size().x / 4, (*it)->Position(), 16) && player->hitflag == false)
		{
			PlaySoundMem(damageSE, DX_PLAYTYPE_BACK);
			player->hp--;
			player->hitflag = true;
		}
		++it;
	}
	for (auto it = pulseManager->_pulseList.begin(); it != pulseManager->_pulseList.end();)
	{
		for (auto it2 = enemyshot->_shotList.begin(); it2 != enemyshot->_shotList.end();)
		{
			if (collision->CircleCollider((*it)->GetPos(), 16 + ((*it)->timer * 10), (*it2)->Position(), 16))
			{
				PlaySoundMem(pulseSE3, DX_PLAYTYPE_BACK);
				(*it2)->endflag = true;
			}
			++it2;
		}
		++it;
	}
	for (auto it = playershot->_shotList.begin(); it != playershot->_shotList.end();)
	{
		if (collision->CircleCollision(boss->Position(), 48, (*it)->Position(), 16))
		{
			boss->hp--;
			PlaySoundMem(damageSE, DX_PLAYTYPE_BACK);
		}
		++it;
	}
	for (auto it = pulseManager->_pulseList.begin(); it != pulseManager->_pulseList.end();)
	{
		if (collision->CircleCollider(boss->Position(), 48, (*it)->GetPos(), (*it)->GetNowSize()))
		{
			boss->hp--;
			PlaySoundMem(damageSE, DX_PLAYTYPE_BACK);
		}
		++it;
	}
}

void GameScene::Pulse()
{
	for (auto it = pulseManager->_pDeviceList.begin(); it != pulseManager->_pDeviceList.end();)
	{
		if ((*it)->hitFlag)
			continue;
		for (auto it2 = playershot->_shotList.begin(); it2 != playershot->_shotList.end();)
		{
			if (collision->CircleCollider((*it)->GetPos(), 16, (*it2)->Position(), 16))
			{
				PlaySoundMem(pulseSE, DX_PLAYTYPE_BACK);
				(*it)->hitFlag = true;
			}
			++it2;
		}
		for (auto it3 = pulseManager->_pulseList.begin(); it3 != pulseManager->_pulseList.end();)
		{
			if (collision->ColorCollider((*it)->GetPos(), 16, (*it3)->GetPos(), (*it3)->GetNowSize(), (*it)->GetType(), (*it3)->GetType()))
			{
				PlaySoundMem(pulseSE, DX_PLAYTYPE_BACK);
				(*it)->hitFlag = true;
			}
			++it3;
		}
		++it;
	}
	for (auto it = pulseManager->_pulseList.begin(); it != pulseManager->_pulseList.end();) {
		if ((*it)->GetHitCheckFlag()) {
			++it;
			continue;
		}
		for (auto it2 = std::next(pulseManager->_pulseList.begin(), 0); it2 != std::next(pulseManager->_pulseList.end(), 0);) {
			if ((*it2)->GetHitCheckFlag()) {
				++it2;
				continue;
			}
			if (it == it2) {
				++it2;
				continue;
			}
			if (collision->CircleCollider((*it)->GetPos(), (*it)->GetNowSize(), (*it2)->GetPos(), (*it2)->GetNowSize())) {
				auto howCnt = 0;
				if ((*it)->GetHowlingCount() == 0 && (*it2)->GetHowlingCount() == 0)
					howCnt = 1;
				else
					howCnt = (*it)->GetHowlingCount() + (*it2)->GetHowlingCount();
				pulseManager->PulseOn(collision->GetDistance((*it)->GetPos(), (*it)->GetNowSize(), (*it2)->GetPos(), (*it2)->GetNowSize()) - Vector2D(((*it)->GetNowSize() + (*it2)->GetNowSize()), ((*it)->GetNowSize() + (*it2)->GetNowSize())),
					collision->TypeCol((*it)->GetType(), (*it2)->GetType()),
					(((*it)->GetNowSize() + (*it2)->GetNowSize())) / 1.5, true, howCnt);
				PlaySoundMem(pulseSE2, DX_PLAYTYPE_BACK);
				(*it)->hitCheckFlag = true;
				(*it2)->hitCheckFlag = true;
				++it2;
			}
			++it2;
		}
		++it;
	}

	int pC = 0;
	for (auto p = pulseManager->_pulseList.begin(); p != pulseManager->_pulseList.end();)
	{
		if (collision->CircleCollider(player->Position(), 16, (*p)->GetPos(), (*p)->GetNowSize())) {
			player->onPulseFlag = true;
		}
		else {
			pC++;
		}
		++p;
		if (pC >= pulseManager->_pulseList.size()) {
			player->onPulseFlag = false;
		}
	}

}

void GameScene::EnemyAttack()
{
	static int angle;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (manager->data[i].shotflag == true && manager->data[i].s_pattern == 0 && manager->data[i].endflag == false)
		{
			enemyshot->EShot(manager->data[i].pos, 90, manager->data[i].s_velocity);
			manager->data[i].count = 0;
		}
		if (manager->data[i].shotflag == true && manager->data[i].s_pattern == 1 && manager->data[i].endflag == false)
		{
			enemyshot->EShot(manager->data[i].pos, 135, manager->data[i].s_velocity);
			manager->data[i].count = 0;
		}
		if (manager->data[i].shotflag == true && manager->data[i].s_pattern == 2 && manager->data[i].endflag == false)
		{
			enemyshot->EShot(manager->data[i].pos, 45, manager->data[i].s_velocity);
			manager->data[i].count = 0;
		}
		if (manager->data[i].shotflag == true && manager->data[i].s_pattern == 3 && manager->data[i].endflag == false)
		{
			enemyshot->EShot(manager->data[i].pos, 45, manager->data[i].s_velocity);
			enemyshot->EShot(manager->data[i].pos, 90, manager->data[i].s_velocity);
			enemyshot->EShot(manager->data[i].pos, 135, manager->data[i].s_velocity);
			manager->data[i].count = 0;
		}
		if (manager->data[i].shotflag == true && manager->data[i].s_pattern == 4 && manager->data[i].endflag == false)
		{
			angle += 30;

			angle = angle % 360;
			enemyshot->EShot(manager->data[i].pos, angle, manager->data[i].s_velocity);
			manager->data[i].count = 0;
		}

	}
}

void GameScene::BossAttack()
{
	static int angle;
	static int angle1 = 180;
	static int angle2;
	static bool shotflag = false;
	static int num = 0;
	static int shotcount = 0;
	if (boss->shot_pattern == 0 && boss->shotflag == true)
	{
		for (int i = 0; i < 360; i += 30)
		{
			enemyshot->EShot(boss->ShotPosition(), i, 1);
		}
		boss->count = 0;
	}
	if (boss->shot_pattern == 1 && boss->shotflag == true)
	{
		angle += 3;
		angle = angle % 360;
		angle1 += 3;
		angle1 = angle1 % 360;
		enemyshot->EShot(boss->ShotPosition(), 135, 2);
		enemyshot->EShot(boss->ShotPosition(), 45, 2);
		enemyshot->EShot(boss->ShotPosition(), angle, 2);
		enemyshot->EShot(boss->ShotPosition(), angle1, 2);
		boss->count = 0;
	}
	if (boss->shot_pattern == 2 && boss->shotflag == true)
	{
		if (angle > 150)
		{
			shotflag = true;
		}
		if (angle < 30)
		{
			shotflag = false;
		}
		if (!shotflag)
		{
			angle += 5;
		}
		else
		{
			angle -= 5;
		}
		enemyshot->EShot(boss->ShotPosition(), angle, 2);
		boss->count = 0;
	}
	if (boss->shot_pattern == 3 && boss->shotflag == true)
	{
		if (angle2 > 120)
		{
			shotflag = true;
		}
		if (angle2 < 0)
		{
			shotflag = false;
		}
		if (!shotflag)
		{
			angle2 += 2;
		}
		else
		{
			angle2 -= 2;
		}
		enemyshot->EShot(boss->ShotPosition(), angle2, 1);
		if (angle > 330)
		{
			num++;
		}
		if (num > 5)
		{
			shotcount++;
		}
		else
		{
			angle += 30;
			angle = angle % 360;
			enemyshot->EShot(boss->ShotPosition(), angle, 2);
		}
		if (shotcount > 60)
		{
			num = 0;
			shotcount = 0;
		}
	}
}

void GameScene::BossAttack1()
{

}


void GameScene::Release()
{
	DeleteSoundMem(damageSE);
	DeleteSoundMem(pulseSE);
	DeleteSoundMem(pulseSE2);
	DeleteSoundMem(pulseSE3);
	DeleteSoundMem(playBGM);
	delete manager;
	delete enemyshot;
	delete player;
	delete playershot;
	delete collision;
	delete pulseManager;
	delete keyfrem;

}
