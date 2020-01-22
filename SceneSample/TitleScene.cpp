#include "TitleScene.h"
#include "DxLib.h"
#include "GraphFactory.h"
#include "SceneManager.h"

void TitleScene::Initialize()
{
	//_titleImage = GraphFactory::Instance().LoadGraph("img\\title.png");
	_titleImage = GraphFactory::Instance().LoadGraph("img\\title_01.png");
	_titleBGM = LoadSoundMem("sound\\titleBGM.mp3");
	PlaySoundMem(_titleBGM, DX_PLAYTYPE_LOOP);
	keyfrem = new Keyfrem;


	_titleCount = 0;
	colorCnt = 1;
	fadeCount = 0;
	fadeFlag = false;
}

void TitleScene::Update()
{
	if (_titleCount < 120)
	{
		_titleCount++;
	}
	else
	{
		_titleCount = 0;
		colorCnt *= -1;
	}
	DrawGraph(0, 0, _titleImage, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_ADD, 200);

	RenderPulse();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	keyfrem->gadUpdateKey();
	//int key = GetJoypadInputState(DX_INPUT_PAD1);

	if (keyfrem->Key[KEY_INPUT_SPACE] == 1) {
		//	ゲームシーンに移りたいが、どのようにシーンを変更するか？
		//SceneManager::Instance().LoadScene("Game");
		fadeFlag = true;
	}

	if (fadeFlag) {
		DrawCircle(240, 300, fadeCount * 10, GetColor(0, 0, 0), TRUE, 1);
		fadeCount++;
	}
	if (fadeCount > 180) {
		SceneManager::Instance().LoadScene("Game");
	}

}

void TitleScene::RenderPulse()
{
	if (colorCnt < 0) {
		DrawOval(250, 300, 60 + _titleCount, 30 + _titleCount * 0.5, GetColor(230, 0, 0), 1, 10);
	}
	else {
		DrawOval(250, 300, 60 + _titleCount, 30 + _titleCount * 0.5, GetColor(0, 0, 230), 1, 10);
	}
	DrawOval(250, 300, 60 + _titleCount, 30 + _titleCount * 0.5, GetColor(120, 100, 100), 1, 5);
}

void TitleScene::Release()
{
	GraphFactory::Instance().EraseGraph("img\\title_01.png");
	DeleteSoundMem(_titleBGM);
	delete keyfrem;
}
