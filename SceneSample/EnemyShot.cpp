#include "EnemyShot.h"

EnemyShot::~EnemyShot()
{
	// 解放する
	for (auto shot : _shotList) {
		delete shot;
	}
}

void EnemyShot::EShot(const Vector2D & pos)
{
}

void EnemyShot::EShot(const Vector2D & pos, float angle,float velocity)
{
	// 弾を動的に生成する
	EnemyBullet* shot = new EnemyBullet(pos, angle,velocity);

	// 弾の初期化
	shot->Start();

	// 弾をリストに格納する
	_shotList.push_back(shot);
	
}

void EnemyShot::Update()
{
	// イテレータを使用して全ての弾を処理
	for (auto it = _shotList.begin(); it != _shotList.end();)
	{
		// 弾を更新
		(*it)->Update();
		if ((*it)->Position().x < -30 || (*it)->Position().x > 480 ||
			(*it)->Position().y < 0 || (*it)->Position().y > 600 || 
			(*it)->endflag == true) {
			// 弾を消す
			delete *it;
			it = _shotList.erase(it);
			continue;
		}
		// 次のイテレータを参照
		++it;
	}
}

void EnemyShot::Render()
{
	for (auto shot : _shotList)
	{
		shot->Render();
	}
}
