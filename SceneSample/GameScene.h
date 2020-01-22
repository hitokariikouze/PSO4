#pragma once
#include "Scene.h"
#include "Player.h"
#include "PlayerShot.h"
#include "EnemyShot.h"
#include "Keyfrem.h"
#include "EnemyManager.h"
#include "Collision.h"
#include "Pulse.h"
#include "PulseDevice.h"
#include "PulseManager.h"
#include "StarDot.h"
#include "Vector2D.h"
#include "FPS.h"
#include "Boss.h"

class GameScene : public Scene
{
private:
	Player* player;
	PlayerShot* playershot;
	EnemyShot* enemyshot;
	Keyfrem* keyfrem;
	EnemyManager* manager;
	Collision* collision;
	PulseManager* pulseManager;
	std::list<StarDot*> starDotList;
	Fps fps;
	Boss* boss;

public:
	GameScene();
	void Initialize();

	void Update();

	void Hit();

	void Pulse();

	void EnemyAttack();

	void BossAttack();
	void Bossdead();
	void Release();

public:
	int _gameImage;
	Vector2D colpos;
	Vector2D pos;
	int timer;
	int timer2;

	int playBGM;
	int stageBGM;
	int damageSE;
	int pulseSE;
	int pulseSE2;
	int pulseSE3;
	int exSE1;

	int destroyCount;

	int bossdeadCount;
	bool bossdead;
	bool clear;
	int fadeCount;
	bool fadeFlag;
};

