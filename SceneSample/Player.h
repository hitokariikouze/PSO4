#pragma once
#include <DxLib.h>
#include "Vector2D.h"

// プレイヤークラス
class Player
{
public:
	// コンストラクタ
	Player(Vector2D pos);

	// 開始
	void Start();

	// 描画
	void Render();

	// 更新
	void Update();

	// 発射ボタン押下
	int OnShotButton();

	Vector2D Position() {
		return _position;
	}

	Vector2D Size() {
		return _size;
	}
	int hp;
private:
	Vector2D _position; // 座標
	Vector2D _size; // サイズ
	int grp; // 画像ID
	
	bool shotFlag;
};
