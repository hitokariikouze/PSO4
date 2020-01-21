#include "EnemyBullet.h"
#define _USE_MATH_DEFINES // M_PIを使用するため
#include <math.h>

EnemyBullet::EnemyBullet(Vector2D pos, float angle, float velocity) : _position(pos), _size(Vector2D(32, 32))
{
	// ラジアン角に変換し渡す
	auto x = cos((M_PI / 180)*angle)*velocity;
	auto y = sin((M_PI / 180)*angle)*velocity;

	_velocity = Vector2D(x, y);
}

EnemyBullet::~EnemyBullet()
{
	// 画像を開放する
	DeleteGraph(grp);
}

void EnemyBullet::Start()
{
	// 画像の読み込みを行う
	grp = LoadGraph("img\\EB.png");

	_animFrameCount = 0;
	endflag = false;
}

void EnemyBullet::Render()
{
	// 反転フラグをTRUEにしているのは画像の向きの関係上

	DrawGraph(_position.x, _position.y, grp, TRUE);
}

void EnemyBullet::Update()
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
