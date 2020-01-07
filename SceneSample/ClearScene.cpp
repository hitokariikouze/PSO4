#include "ClearScene.h"
#include "DxLib.h"
#include "GraphFactory.h"
#include "SceneManager.h"

void ClearScene::Initialize()
{
	_clearimg = GraphFactory::Instance().LoadGraph("img\\pipo-battlebg003b.jpg");
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
	GraphFactory::Instance().EraseGraph("img\\pipo-battlebg003b.jpg");
}
