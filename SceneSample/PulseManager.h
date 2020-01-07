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

	void PulseOn(Vector2D pos);

	~PulseManager();

public:
	std::list<Pulse*> _pulseList; //パルスリスト
	std::list<PulseDevice*> _pDeviceList; //パルス発生装置のリスト

	float timer;
};