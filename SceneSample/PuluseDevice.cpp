#include "PulseDevice.h"


PulseDevice::PulseDevice(Vector2D pos, int type) :_position(pos), _size(Vector2D(32, 32)), _type(type)
{
	hitFlag = false;
}

PulseDevice::~PulseDevice() {

}

void PulseDevice::Render()
{
	if (_type == 1)
	{
		DrawCircle(_position.x + 16, _position.y + 16, 16, GetColor(0, 0, 255), 1, 1);
	}
	if (_type == 2)
	{
		DrawCircle(_position.x + 16, _position.y + 16, 16, GetColor(255, 0, 0), 1, 1);
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