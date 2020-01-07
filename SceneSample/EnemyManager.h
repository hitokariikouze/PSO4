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

	bool endflag;
}ENEMYDATA;


class EnemyManager
{
public:
	ENEMYDATA data[10];
	EnemyManager();
	void Start();
	void Render();
	void Update();
	void Move();
	void Out();
private:
	int grp;
	int gh;
	int time_count;
};


