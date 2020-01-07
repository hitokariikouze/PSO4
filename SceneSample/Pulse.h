#pragma once
#include "DxLib.h"
#include "Vector2D.h"

class Pulse
{
public:

	Pulse(Vector2D pos);

	~Pulse();

	// 開始
	void Start();

	void Update();

	void Render();

	float TimeCount();

	bool GetDeadFlag();

	Vector2D GetPos();

	float GetNowSize();

public:
	bool DeadFlag;

private:
	float timer;
	int grp; // 画像ID
	Vector2D _position; // 座標
	float _size; // 画像サイズ
};
