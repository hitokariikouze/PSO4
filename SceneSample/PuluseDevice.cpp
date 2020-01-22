#include "PulseDevice.h"


PulseDevice::PulseDevice(Vector2D pos, int type) :_position(pos), _size(Vector2D(32, 32)), _type(type)
{
	hitFlag = false;
	agrp = GraphFactory::Instance().LoadGraph("img\\parusitem03.png");
	bgrp = GraphFactory::Instance().LoadGraph("img\\parusitem04.png");
	timer = 0;
}

PulseDevice::~PulseDevice() {

}

void PulseDevice::Render()
{
	timer++;
	if (_type == 1)
	{
		DrawRotaGraph3(_position.x+16, _position.y+16, 128, 128, 0.125, 0.125, timer/10, agrp, TRUE);
	}
	if (_type == 2)
	{
		DrawRotaGraph3(_position.x+16, _position.y+16, 128, 128, 0.125, 0.125, timer/10, bgrp, TRUE);
	}
}

void PulseDevice::Hit(bool HitFlag)
{
	if (!HitFlag)
		return;
	else
		hitFlag = true;
}

Vector2D PulseDevice::GetPos()
{
	return _position;
}

int PulseDevice::GetType()
{
	return _type;
}

float PulseDevice::GetRadius()
{
	return _size.x / 2;
}