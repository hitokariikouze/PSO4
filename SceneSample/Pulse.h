#pragma once
#include "DxLib.h"
#include "Vector2D.h"

class Pulse
{
public:

	Pulse(Vector2D pos);

	~Pulse();

	// �J�n
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
	int grp; // �摜ID
	Vector2D _position; // ���W
	float _size; // �摜�T�C�Y
};
