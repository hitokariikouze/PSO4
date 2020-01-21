#pragma once
#include "DxLib.h"
#include "Vector2D.h"

class Pulse
{
public:

	Pulse(Vector2D pos, int type, float radius, bool howlingPulse, int howlingCnt);

	~Pulse();

	// 開始
	void Start();

	void Update();

	void Render();

	float TimeCount();

	bool GetDeadFlag();

	Vector2D GetPos();

	int GetType();

	float GetNowSize();

	bool GetHitCheckFlag();

	int GetHowlingCount();

public:
	bool DeadFlag;

	bool hitCheckFlag;
	float _size; // 画像サイズ
	float timer;

	bool howlingPulseFlag; //共鳴で生まれたかそうでないか
private:

	int grp; // 画像ID
	Vector2D _position; // 座標
	int _type;
	Vector2D colpos;

	float _radius;
	int howlingCount; //共鳴の回数
};
