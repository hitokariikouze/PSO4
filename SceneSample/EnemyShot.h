
#pragma once
#include <list>
#include "Vector2D.h"
#include "EnemyBullet.h"
#include "WindowInfo.h"

// 弾を撃つクラス
class EnemyShot
{
public:
	// デストラクタ
	~EnemyShot();

	// 弾を撃つ
	void EShot(const Vector2D& pos);
	void EShot(const Vector2D& pos, float angle,float velocity);

	// 処理の更新
	void Update();

	// 描画
	void Render();

public:
	std::list<EnemyBullet*> _shotList; // 弾リスト
	
};