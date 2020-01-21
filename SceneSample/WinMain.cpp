#include "DxLib.h"
#include <string>
#include "WindowInfo.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "ClearScene.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//	Window���[�h�̐ݒ��Window�^�C�g����ݒ肷��
	ChangeWindowMode(true);
	SetMainWindowText("�V�[���؂�ւ�");

	//	��ʃT�C�Y��ݒ�
	SetGraphMode(WindowInfo::WindowWidth, WindowInfo::WindowHeight, 16);
	if (DxLib_Init() == -1)	// �c�w���C�u��������������
	{
		return -1;				// �G���[���N�����璼���ɏI��
	}

	//	�`�����w��
	SetDrawScreen(DX_SCREEN_BACK);

	//	��ʔw�i�̐F��ݒ肷��
	SetBackgroundColor(0, 0, 0);

	SceneManager::Instance().AddScene("Title", new TitleScene);
	SceneManager::Instance().AddScene("Game", new GameScene);
	SceneManager::Instance().AddScene("Clear", new ClearScene);

	SceneManager::Instance().StartScene("Title");

	SceneManager::Instance().Update();

	_CrtDumpMemoryLeaks();

	//	�������
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;					// �\�t�g�̏I��
}
