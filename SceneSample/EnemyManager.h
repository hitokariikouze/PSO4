#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Vector2D.h"
#include "number.h"
typedef struct {

	Vector2D pos;

	int type;//“Gí—Ş

	int m_pattern;//ˆÚ“®ƒpƒ^[ƒ“

	int in_time;//oŒ»ŠÔ

	int stop_time;//’â~ŠÔ

	int out_time;//‹AŠÒŠÔ

	int x;//xÀ•W

	int y;//yÀ•W

	int hp;//HP

	int scount;//’eŠÔŠu

	int s_pattern;//’eí—Ş

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


