#pragma once
#include <list>
#include "Vector2D.h"
#include "BulletStar.h"
#include "WindowInfo.h"

// 弾を撃つクラス
class PlayerShot
{
public:
	// デストラクタ
	~PlayerShot();

	// 弾を撃つ
	void Shot(const Vector2D& pos);
	void Shot(const Vector2D& pos, float angle);

	// 処理の更新
	void Update();

	// 描画
	void Render();

public:
	std::list<BulletStar*> _shotList; // 弾リスト
};
