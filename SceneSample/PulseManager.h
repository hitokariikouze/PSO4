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
	std::list<Pulse*> _pulseList; //�p���X���X�g
	std::list<PulseDevice*> _pDeviceList; //�p���X�������u�̃��X�g
	int num;
	int cnum;
	Vector2D _position;
	int _type;
	float timer;
};