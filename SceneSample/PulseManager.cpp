#include "PulseManager.h"
#include "Collision.h"
#include "WindowInfo.h"

PulseManager::~PulseManager()
{
	for (auto pDevice : _pDeviceList) {
		delete pDevice;
	}
	num = 1;
	cnum = 1;
}

void PulseManager::AddPulse()
{

	PulseDevice* pDevice = new PulseDevice(_position, _type);
	_pDeviceList.push_back(pDevice);
}

void PulseManager::AddPosition()
{
	if (num == 1)
	{
		_position.x = GetRand(WindowInfo::WindowWidth - 240) + 80;
		_position.y = GetRand(WindowInfo::WindowHeight - 300) + 40;
	}
	if (num == 2)
	{
		_position.x = GetRand(WindowInfo::WindowWidth - 240) + 160;
		_position.y = GetRand(WindowInfo::WindowHeight - 300) + 200;
	}
	if (num == 3)
	{
		_position.x = GetRand(WindowInfo::WindowWidth - 240) + 80;
		_position.y = GetRand(WindowInfo::WindowHeight - 300) + 200;
	}
	if (num == 4)
	{
		_position.x = GetRand(WindowInfo::WindowWidth - 240) + 160;
		_position.y = GetRand(WindowInfo::WindowHeight - 300) + 40;
		num = 0;
	}
	if (cnum == 1)
	{
		_type = 1;
	}
	if (cnum == 2)
	{
		_type = 2;
		cnum = 0;
	}
}

void PulseManager::PulseRender()
{
	if (_type == 1)
	{
		DrawCircle(_position.x + 16, _position.y + 16, 1 + (timer * 0.15), GetColor(0, 0, 255), 0, TRUE);
	}
	if (_type == 2)
	{
		DrawCircle(_position.x + 16, _position.y + 16, 1 + (timer * 0.15), GetColor(255, 0, 0), 0, TRUE);
	}
}

void PulseManager::PulseOn(Vector2D pos, int type, float radius, bool howlingFlag, int howlingCnt)
{
	if (!howlingFlag) {
		Pulse* pulse = new Pulse(pos, type, radius, false, 0);
		_pulseList.push_back(pulse);
		pulse->Start();
	}
	else {
		Pulse* pulse = new Pulse(pos, type, radius, true, howlingCnt);
		_pulseList.push_back(pulse);
		pulse->Start();
	}
}

void PulseManager::Update()
{
	if (timer < 80) {
		timer++;
		PulseRender();
	}
	else {
		AddPulse();
		AddPosition();
		num++;
		cnum++;
		timer = 0;
	}

	for (auto it = _pDeviceList.begin(); it != _pDeviceList.end();) {
		if ((*it)->hitFlag) {
			PulseOn((*it)->GetPos(), (*it)->GetType(), (*it)->GetRadius(), false, 0);
			delete *it;
			it = _pDeviceList.erase(it);
			continue;
		}
		++it;
	}

	for (auto it = _pulseList.begin(); it != _pulseList.end();) {
		(*it)->Update();
		if ((*it)->GetDeadFlag()) {
			delete *it;
			it = _pulseList.erase(it);
			continue;
		}
		++it;
	}

}

void PulseManager::Render() {
	for (auto pDevice : _pDeviceList) {
		pDevice->Render();
	}
	for (auto pulse : _pulseList) {
		pulse->Render();
	}

}


