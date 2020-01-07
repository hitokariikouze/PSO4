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


