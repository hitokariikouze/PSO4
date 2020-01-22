#pragma once
#include "DxLib.h"
#include "Player.h"
#include "Vector2D.h"
#include "number.h"
typedef struct {

	Vector2D pos;

	int type;//�G���

	int m_pattern;//�ړ��p�^�[��

	int in_time;//�o������

	int stop_time;//��~����

	int out_time;//�A�Ҏ���

	int x;//x���W

	int y;//y���W

	int hp;//HP

	int scount;//�e�Ԋu

	int s_pattern;//�e���

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


