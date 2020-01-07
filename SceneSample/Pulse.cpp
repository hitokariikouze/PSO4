#include "Pulse.h"


Pulse::Pulse(Vector2D pos) :_position(pos)
{
	timer = 0;
	DeadFlag = false;
}

void Pulse::Start()
{
	grp = LoadGraph("img\\pulse.png");
}

void Pulse::Render()
{
	DrawCircle(_position.x + 16, _position.y + 16, 16 + (timer * 10), GetColor(255, 255, 255), 0, 1);
}

void Pulse::Update()
{
	TimeCount();
}

float Pulse::TimeCount()
{
	timer += 0.016f;
	if (timer > 3) {
		DeadFlag = true;
	}
	return timer;
}

bool Pulse::GetDeadFlag() {
	return DeadFlag;
}

Vector2D Pulse::GetPos() {
	return _position;
}

float Pulse::GetNowSize() {
	return 16 + (timer * 10);
}


Pulse::~Pulse()
{
	// ‰æ‘œ‚ðŠJ•ú‚·‚é
	DeleteGraph(grp);
}