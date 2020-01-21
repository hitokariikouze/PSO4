#pragma once
#include "Pulse.h"
#include "PulseDevice.h"
#include <list>
#include "DxLib.h"

class PulseManager
{
public:
	void Update();

	void Render();

	void AddPulse();

	void AddPosition();

	void PulseRender();

	void PulseOn(Vector2D pos,int type, float radius, bool howlingFlag, int howlingCnt);

	~PulseManager();

public:
	std::list<Pulse*> _pulseList; //パルスリスト
	std::list<PulseDevice*> _pDeviceList; //パルス発生装置のリスト
	int num;
	int cnum;
	Vector2D _position;
	int _type;
	float timer;
};