#include "ClearScene.h"
#include "DxLib.h"
#include "GraphFactory.h"
#include "SceneManager.h"

void ClearScene::Initialize()
{
	_clearimg = GraphFactory::Instance().LoadGraph("img\\ending_01.png");
	_endingBGM = LoadSoundMem("sound\\endingBGM.mp3");
	PlaySoundMem(_endingBGM, DX_PLAYTYPE_LOOP);
	keyfrem = new Keyfrem;
}

void ClearScene::Update()
{
	DrawGraph(0, 0, _clearimg, FALSE);

	//int key = GetJoypadInputState(DX_INPUT_PAD1);
	keyfrem->gadUpdateKey();
	if (keyfrem->Key[KEY_INPUT_SPACE] == 1) {
		//	ゲームシーンに移りたいが、どのようにシーンを変更するか？
		SceneManager::Instance().LoadScene("Title");
	}
}

void ClearScene::Release()
{
	GraphFactory::Instance().EraseGraph("img\\ending_01.png");
	DeleteSoundMem(_endingBGM);
	delete keyfrem;
}
