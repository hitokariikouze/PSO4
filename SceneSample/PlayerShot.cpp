#include "PlayerShot.h"

// デストラクタ
PlayerShot::~PlayerShot()
{
	// 解放する
	for (auto shot : _shotList) {
		delete shot;
	}
}

// 弾を発射する
void PlayerShot::Shot(const Vector2D& pos)
{
	// 弾を動的に生成する
	BulletStar* shot = new BulletStar(pos);

	// 弾の初期化
	shot->Start();

	// 弾をリストに格納する
	_shotList.push_back(shot);
}

// 弾を発射する
void PlayerShot::Shot(const Vector2D& pos, float angle)
{
	// 弾を動的に生成する
	BulletStar* shot = new BulletStar(pos, angle);

	// 弾の初期化
	shot->Start();

	// 弾をリストに格納する
	_shotList.push_back(shot);
}

// 処理を更新する
void PlayerShot::Update()
{
	// イテレータを使用して全ての弾を処理
	for (auto it = _shotList.begin(); it != _shotList.end();)
	{
		// 弾を更新
		(*it)->Update();

		// 弾が右画面端を越えたら
		if ((*it)->Position().x + 32 > WindowInfo::WindowWidth) {
			(*it)->Reverse(-1, 1);
		}
		else if ((*it)->Position().x < 0) {
			(*it)->Reverse(-1, 1);
		}
		if ((*it)->Position().y < 0 || (*it)->Position().y > 600) {
			// 弾を消す
			shotflag = false;
			delete *it;
			it = _shotList.erase(it);
			continue;
		}
		// 次のイテレータを参照
		++it;
	}
}

// 弾を画面に表示する
void PlayerShot::Render()
{
	for (auto shot : _shotList)
	{
		shot->Render();
	}
}