#include "Player.h"
#include "GraphFactory.h"

// コンストラクタ

Player::Player(Vector2D pos) : _position(pos), _size(Vector2D(32, 32))
{

}

// 初期化処理
void Player::Start()
{
	grp = GraphFactory::Instance().LoadGraph("img\\pipo-charachip010.png");
	shotFlag = false;
	hp = 10;
}

// 描画
void Player::Render()
{
	DrawRectGraph(static_cast<int>(_position.x),
		static_cast<int>(_position.y), 32, 96,
		static_cast<int>(_size.x),
		static_cast<int>(_size.y), grp, TRUE);
}

// 更新
void Player::Update()
{
	// キー入力を更新
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

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

	_position += velocity;

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