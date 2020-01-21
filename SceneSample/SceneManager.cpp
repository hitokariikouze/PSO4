#include "SceneManager.h"
#include <memory>
#include "DxLib.h"


SceneManager::~SceneManager()
{
	for (auto scene : _scenes)
	{
		delete scene.second;
	}
}

SceneManager & SceneManager::Instance()
{
	static std::unique_ptr<SceneManager>instance(new SceneManager);

	return *instance;
	// TODO: return ステートメントをここに挿入します
}

void SceneManager::AddScene(std::string sceneName, Scene * scene)
{
	if (_scenes.count(sceneName))
		return;
	_scenes[sceneName] = scene;
}

void SceneManager::StartScene(std::string sceneName)
{
	if (!_scenes.count(sceneName))
		return;
	_curretScene = _scenes[sceneName];
}

void SceneManager::LoadScene(std::string sceneName)
{
	if (!_scenes.count(sceneName))
		return;
	_nextScene = _scenes[sceneName];
	_state = SceneState::Release;
}

void SceneManager::Update()
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 )
	{
		ClearDrawScreen();

		SceneUpdate();
		ScreenFlip();
	}
}

void SceneManager::SceneUpdate()
{
	if (!_curretScene)
		return;
	if (_state == SceneState::Initialize) {
		_curretScene->Initialize();
		_state = SceneState::Update;
	}

	_curretScene->Update();

	if (_state == SceneState::Release)
	{
		_curretScene->Release();
		NextScene();
		_state = SceneState::Initialize;
	}
}

void SceneManager::NextScene()
{
	_curretScene = _nextScene;
}
