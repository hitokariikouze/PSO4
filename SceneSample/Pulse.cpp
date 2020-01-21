#include "Pulse.h"


Pulse::Pulse(Vector2D pos, int type, float radius, bool howlingPulse, int howlingCnt) :_position(pos), _type(type)
{
	timer = 0;
	DeadFlag = false;
	hitCheckFlag = false;
	_radius = radius;
	hitCheckFlag = false;
	howlingPulseFlag = howlingPulse;
	howlingCount = howlingCnt;
}

void Pulse::Start()
{
	grp = LoadGraph("img\\pulse.png");
	_size = 16;
	colpos.x = 16;
	colpos.y = 16;
}

void Pulse::Render()
{
	if (_type == 1)
	{
		DrawCircle(_position.x + _radius, _position.y + _radius, GetNowSize(), GetColor(0, 0, 255), 0, 1);
	}
	if (_type == 2)
	{
		DrawCircle(_position.x + _radius, _position.y + _radius, GetNowSize(), GetColor(255, 0, 0), 0, 1);
	}
}

void Pulse::Update()
{
	TimeCount();
}

float Pulse::TimeCount()
{
	timer += 0.06f; //パルスのデカくなるスピード
	if (timer > 6) { // 消えるまでの時間
		DeadFlag = true;
	}
	return timer;
}

bool Pulse::GetDeadFlag() {
	return DeadFlag;
}

Vector2D Pulse::GetPos() {
	return _position;
}

int Pulse::GetType()
{
	return _type;
}

float Pulse::GetNowSize() {
	return _radius + (timer * 10);
}

bool Pulse::GetHitCheckFlag()
{
	return hitCheckFlag;
}

int Pulse::GetHowlingCount()
{
	return howlingCount;
}

Pulse::~Pulse()
{
	// 画像を開放する
	DeleteGraph(grp);
}