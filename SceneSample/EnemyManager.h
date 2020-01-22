#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Vector2D.h"
#include "number.h"
typedef struct {

	Vector2D pos;

	int type;//敵種類

	int m_pattern;//移動パターン

	int in_time;//出現時間

	int stop_time;//停止時間

	int out_time;//帰還時間

	int x;//x座標

	int y;//y座標

	int hp;//HP

	int scount;//弾間隔

	int s_pattern;//弾種類

	float s_velocity;

	int count;

	bool shotflag;

	bool endflag;
}ENEMYDATA;


class EnemyManager
{
public:
	ENEMYDATA data[ENEMY_NUM];
	EnemyManager();
	~EnemyManager();
	void Stage1();
	void Stage2();
	void Stage3();
	void Start();
	void Render();
	void Update();
	void Move();
	void Out();
	void Shot();
	bool bossflag;
	bool miniboss;
private:
	int agrp;
	int bgrp;
	int cgrp;
	int time_count;
	
	/*bool recovery01;
	bool recovery02;
	bool recovery03;*/

};


