#pragma once
#include "DxLib.h"
#include "Vector2D.h"

class Pulse
{
public:

	Pulse(Vector2D pos, int type, float radius, bool howlingPulse, int howlingCnt);

	~Pulse();

	// �J�n
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
	float _size; // �摜�T�C�Y
	float timer;

	bool howlingPulseFlag; //���Ő��܂ꂽ�������łȂ���
private:

	int grp; // �摜ID
	Vector2D _position; // ���W
	int _type;
	Vector2D colpos;

	float _radius;
	int howlingCount; //���̉�
};
