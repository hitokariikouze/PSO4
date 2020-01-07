#include "PulseManager.h"
#include "Collision.h"
#include "WindowInfo.h"

PulseManager::~PulseManager()
{
	for (auto pDevice : _pDeviceList) {
		delete pDevice;
	}
}

void PulseManager::AddPulse()
{
	PulseDevice* pDevice = new PulseDevice(Vector2D(GetRand(WindowInfo::WindowWidth), GetRand(WindowInfo::WindowHeight)));
	_pDeviceList.push_back(pDevice);
}

void PulseManager::PulseOn(Vector2D pos)
{
	Pulse* pulse = new Pulse(pos);
	_pulseList.push_back(pulse);
	pulse->Start();
}

void PulseManager::Update()
{
	if (timer < 20) {
		timer++;
	}
	else {
		AddPulse();
		timer = 0;
	}

	for (auto it = _pDeviceList.begin(); it != _pDeviceList.end();) {
		if ((*it)->hitFlag) {
			PulseOn((*it)->GetPos());
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


