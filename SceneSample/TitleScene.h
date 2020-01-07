#pragma once
#include "Scene.h"
#include "Keyfrem.h"
class TitleScene : public Scene
{
private:
	Keyfrem * keyfrem;
public:
	void Initialize();

	void Update();

	void Release();

private:
	int _titleImage;
};


