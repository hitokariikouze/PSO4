#pragma once
#include "Scene.h"
#include "Player.h"
#include "PlayerShot.h"
#include "Keyfrem.h"
#include "EnemyManager.h"
#include "Collision.h"
#include "Pulse.h"
#include "PulseDevice.h"
#include "PulseManager.h"

class GameScene : public Scene
{
private:
	Player* player;
	PlayerShot* playershot;
	Keyfrem* keyfrem;
	EnemyManager* manager;
	Collision* collision;
	PulseManager* pulseManager;
public:
	GameScene();
	void Initialize();

	void Update();

	void Hit();

	void Release();

public:
	int _gameImage;
	

};

