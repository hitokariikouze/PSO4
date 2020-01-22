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

	void RenderPulse();
private:
	int _titleImage;
	int _titleBGM;

	float _titleCount;
	int colorCnt;

	int fadeCount;
	bool fadeFlag;
};


