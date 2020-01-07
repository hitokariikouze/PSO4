#include "TitleScene.h"
#include "DxLib.h"
#include "GraphFactory.h"
#include "SceneManager.h"

void TitleScene::Initialize()
{
	_titleImage = GraphFactory::Instance().LoadGraph("img\\pipo-battlebg018b.jpg");
	keyfrem = new Keyfrem;
	
}

void TitleScene::Update()
{
	DrawGraph(0, 0, _titleImage, FALSE);
	keyfrem->gadUpdateKey();
	//int key = GetJoypadInputState(DX_INPUT_PAD1);

	if (keyfrem->Key[KEY_INPUT_SPACE] == 1) {
		//	ゲームシーンに移りたいが、どのようにシーンを変更するか？
		SceneManager::Instance().LoadScene("Game");
	}

}

void TitleScene::Release()
{
	GraphFactory::Instance().EraseGraph("img\\pipo-battlebg018b.jpg");
}
