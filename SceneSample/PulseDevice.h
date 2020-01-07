#pragma once
#include <list>
#include "Vector2D.h"
#include "Pulse.h"
#include "WindowInfo.h"

class PulseDevice
{
public:
	PulseDevice(Vector2D pos);

	~PulseDevice();

	void Render();

	void Hit(bool HitFlag);

	Vector2D GetPos();

public:
	bool hitFlag;


private:
	Vector2D _position;
	Vector2D _size;
	int grp;
};
