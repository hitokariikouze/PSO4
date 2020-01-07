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
	std::list<Pulse*> _pulseList; //�p���X���X�g
	std::list<PulseDevice*> _pDeviceList; //�p���X�������u�̃��X�g

	float timer;
};