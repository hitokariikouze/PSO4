#include "Player.h"
#include "GraphFactory.h"
#include "WindowInfo.h"
#include <math.h>

// コンストラクタ

Player::Player(Vector2D pos) : _position(pos), _size(Vector2D(32, 32))
{

}

Player::~Player() {
	GraphFactory::Instance().EraseGraph("img\\Player.png");
}

// 初期化処理
void Player::Start()
{
	grp = GraphFactory::Instance().LoadGraph("img\\Player.png");
	shotFlag = false;
	hitflag = false;
	hp = 10;
	count = 0;
	onPulseFlag = false;
	timer = 0;
}

// 描画
void Player::Render()
{
	DrawGraph(_position.x, _position.y, grp, TRUE);
	if (onPulseFlag) {
		int centerx = _position.x + 16;
		int centery = _position.y + 16;
		DrawTriangle(centerx - (timer), (centery - 8) + (timer), centerx, (centery - 8) - (timer), centerx + (timer), (centery - 8) + (timer), GetColor(100, 250, 100), false);
		DrawTriangle(centerx - (timer), (centery + 8) - (timer), centerx, (centery + 8) + (timer), centerx + (timer), (centery + 8) - (timer), GetColor(100, 250, 100), false);
	}

#pragma region HP表示
	DrawLine(16, 404, 16, 196, GetColor(250, 250, 250), 16);
	DrawLine(16, 400, 16, 200, GetColor(0, 0, 0), 8);
	DrawLine(16, 400, 16, 400 + (hp * -20), GetColor(200, 0, 0), 8);
	DrawFormatString(8, 410, GetColor(255, 0, 0), "HP:%i", hp);
#pragma endregion

}

// 更新
void Player::Update()
{
	if (timer >= 30) {
		timer = 0;
	}
	else {
		timer++;
	}

	// キー入力を更新
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	linex = WindowInfo::WindowWidth - _position.x;
	liney = WindowInfo::WindowWidth - _position.y;

	// 移動量
	Vector2D velocity;
	// 上キーで前に進む
	if (key&PAD_INPUT_UP) {
		velocity.y -= 2;
	}
	// 下キーで後ろに進む
	if (key&PAD_INPUT_DOWN) {
		velocity.y += 2;
	}
	// 右キーで右に進む
	if (key&PAD_INPUT_RIGHT) {
		velocity.x += 2;
	}
	// 左キーで左に進む
	if (key&PAD_INPUT_LEFT) {
		velocity.x -= 2;
	}

	if (WindowInfo::WindowWidth - 32 < _position.x + velocity.x || WindowInfo::WindowHeight - 32 < _position.y + velocity.y ||
		-8 > _position.x + velocity.x || -8 > _position.y + velocity.y)
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	_position += velocity;
	if (hitflag == true)
	{
		count++;
		if (count > 120)
		{
			hitflag = false;
			count = 0;
		}
	}
}

// 弾を発射する
int Player::OnShotButton()
{
	// ローカルで静的変数を宣言すると
	// その値は関数が終了しても維持される（ちょっと悪手）
	static int inputFrame = 0;

	// キーボードのスペースキーが押されたら
	if (CheckHitKey(KEY_INPUT_C)) {
		inputFrame++;
	}
	else {
		inputFrame = 0;
	}

	return inputFrame;

}

int Player::GetShotDamage()
{
	if (!onPulseFlag)
		return 1;
	return 100;
}