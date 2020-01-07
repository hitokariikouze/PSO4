#pragma once
#include "Scene.h"
#include "Keyfrem.h"
class ClearScene : public Scene
{
private:
	Keyfrem * keyfrem;
public:
	void Initialize();

	void Update();

	void Release();

private:
	int _clearimg;
};

