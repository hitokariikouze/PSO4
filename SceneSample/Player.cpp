#include "Player.h"
#include "GraphFactory.h"
#include "WindowInfo.h"
#include <math.h>

// �R���X�g���N�^

Player::Player(Vector2D pos) : _position(pos), _size(Vector2D(32, 32))
{

}

Player::~Player() {
	GraphFactory::Instance().EraseGraph("img\\Player.png");
}

// ����������
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

// �`��
void Player::Render()
{
	DrawGraph(_position.x, _position.y, grp, TRUE);
	if (onPulseFlag) {
		int centerx = _position.x + 16;
		int centery = _position.y + 16;
		DrawTriangle(centerx - (timer), (centery - 8) + (timer), centerx, (centery - 8) - (timer), centerx + (timer), (centery - 8) + (timer), GetColor(100, 250, 100), false);
		DrawTriangle(centerx - (timer), (centery + 8) - (timer), centerx, (centery + 8) + (timer), centerx + (timer), (centery + 8) - (timer), GetColor(100, 250, 100), false);
	}

#pragma region HP�\��
	DrawLine(16, 404, 16, 196, GetColor(250, 250, 250), 16);
	DrawLine(16, 400, 16, 200, GetColor(0, 0, 0), 8);
	DrawLine(16, 400, 16, 400 + (hp * -20), GetColor(200, 0, 0), 8);
	DrawFormatString(8, 410, GetColor(255, 0, 0), "HP:%i", hp);
#pragma endregion

}

// �X�V
void Player::Update()
{
	if (timer >= 30) {
		timer = 0;
	}
	else {
		timer++;
	}

	// �L�[���͂��X�V
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	linex = WindowInfo::WindowWidth - _position.x;
	liney = WindowInfo::WindowWidth - _position.y;

	// �ړ���
	Vector2D velocity;
	// ��L�[�őO�ɐi��
	if (key&PAD_INPUT_UP) {
		velocity.y -= 2;
	}
	// ���L�[�Ō��ɐi��
	if (key&PAD_INPUT_DOWN) {
		velocity.y += 2;
	}
	// �E�L�[�ŉE�ɐi��
	if (key&PAD_INPUT_RIGHT) {
		velocity.x += 2;
	}
	// ���L�[�ō��ɐi��
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

// �e�𔭎˂���
int Player::OnShotButton()
{
	// ���[�J���ŐÓI�ϐ���錾�����
	// ���̒l�͊֐����I�����Ă��ێ������i������ƈ���j
	static int inputFrame = 0;

	// �L�[�{�[�h�̃X�y�[�X�L�[�������ꂽ��
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