#pragma once
#include "TitleScene.h"
#include "GameScene.h"
#include "Scene.h"
#include <unordered_map>
enum SceneState
{
	Initialize,Update,Release
};

class SceneManager
{
private:
	SceneManager() : _state(SceneState::Initialize),
		_curretScene(nullptr),_nextScene(nullptr){}
	SceneManager(const SceneManager&){}
	SceneManager& operator = (const SceneManager&){}
public:
	~SceneManager();
	static SceneManager& Instance();

	void AddScene(std::string sceneName, Scene* scene);

	void StartScene(std::string sceneName);

	void LoadScene(std::string sceneName);

	void Update();
private:
	void SceneUpdate();

	void NextScene();
private:
	Scene* _curretScene;	//	���ݎ��s���Ă���V�[��
	Scene* _nextScene;		//	���Ɏ��s����V�[��
	SceneState _state;		//	�V�[���̏��
	std::unordered_map<std::string, Scene*>_scenes;
};
