#define _USE_MATH_DEFINES // M_PIを使用するため
#include "BulletStar.h"
#include <cmath>

// コンストラクタ
BulletStar::BulletStar(Vector2D pos) :_position(pos), _size(Vector2D(32, 32))
{
	_velocity = Vector2D(1, 0);
}

// コンストラクタ（引数あり）
BulletStar::BulletStar(Vector2D pos, float angle) : _position(pos), _size(Vector2D(32, 32))
{
	float velecity = 8.0f;

	// ラジアン角に変換し渡す
	auto x = cos((M_PI / 180)*angle)*velecity;
	auto y = sin((M_PI / 180)*angle)*velecity;

	_velocity = Vector2D(x, y);
}

// デストラクタ
BulletStar::~BulletStar()
{
	// 画像を開放する
	DeleteGraph(grp);
}

void BulletStar::Start()
{
	// 画像の読み込みを行う
	grp = LoadGraph("img\\pipo-mapeffect011j.png");

	_animFrameCount = 0;
}

// 弾を画面に表示する
void BulletStar::Render()
{
	// 反転フラグをTRUEにしているのは画像の向きの関係上
	DrawRectGraph(static_cast<int>(_position.x),
		static_cast<int>(_position.y), _offset.x, _offset.y,
		static_cast<int>(_size.x),
		static_cast<int>(_size.y), grp, TRUE, TRUE);
}

// 上下左右反転
void BulletStar::Reverse(int x, int y) {
	_velocity.x *= x;
	_velocity.y *= y;
}

// 更新
void BulletStar::Update()
{
	// アニメーションの実行
	_animFrameCount++;

	// 画像のオフセット位置を変更
	auto sheetNo = _animFrameCount / AnimationSpeed;
	_offset.x = (sheetNo%HorizonSheet)*_size.x;
	_offset.y = ((sheetNo / HorizonSheet) % VerticalSheet)*_size.y;

	// 弾の座標を移動させる

	_position += _velocity;

}

