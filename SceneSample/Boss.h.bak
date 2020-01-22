#pragma once
#include "DxLib.h"
#include "EnemyShot.h"
#include "Vector2D.h"

class Boss
{
public:
	Boss(Vector2D pos,int type);
	~Boss();
	void Start();
	void Render();
	void Update();
	void Move();
	void Move1();
	void Shot();

	void MovePattern0();
	void MovePattern1();
	void MovePattern2();
	void MovePattern3();

	void ShotChange();

	void MoveChange();
	void MoveChange1();

	void MoveInit(double bx, double by, int state);


	Vector2D Position() {
		return _position;
	}

	Vector2D ShotPosition()
	{
		return shot_position;
	}

	Vector2D Size() {
		return _size;
	}
	int hp;
public:
	EnemyShot * shot;
	Vector2D _position; // 座標
	Vector2D shot_position;
	Vector2D _size; // サイズ
	int grp,gh;
	int count,waitcount,scount[3];
	int move_pattern, shot_pattern;
	bool shotflag;
	int _type;
private:
	int angle, raise,raise1;
	int prev_x, prev_y, movex, movey;
	bool wait;
	int p3_state;
};
