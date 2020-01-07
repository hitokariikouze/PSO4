#include "PulseDevice.h"


PulseDevice::PulseDevice(Vector2D pos) :_position(pos), _size(Vector2D(32, 32))
{
	hitFlag = false;
}

PulseDevice::~PulseDevice() {

}

void PulseDevice::Render()
{
	DrawCircle(_position.x + 16, _position.y + 16, 16, GetColor(255, 0, 255), 1, 1);
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