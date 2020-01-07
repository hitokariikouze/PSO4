#define _USE_MATH_DEFINES // M_PI���g�p���邽��
#include "BulletStar.h"
#include <cmath>

// �R���X�g���N�^
BulletStar::BulletStar(Vector2D pos) :_position(pos), _size(Vector2D(32, 32))
{
	_velocity = Vector2D(1, 0);
}

// �R���X�g���N�^�i��������j
BulletStar::BulletStar(Vector2D pos, float angle) : _position(pos), _size(Vector2D(32, 32))
{
	float velecity = 8.0f;

	// ���W�A���p�ɕϊ����n��
	auto x = cos((M_PI / 180)*angle)*velecity;
	auto y = sin((M_PI / 180)*angle)*velecity;

	_velocity = Vector2D(x, y);
}

// �f�X�g���N�^
BulletStar::~BulletStar()
{
	// �摜���J������
	DeleteGraph(grp);
}

void BulletStar::Start()
{
	// �摜�̓ǂݍ��݂��s��
	grp = LoadGraph("img\\pipo-mapeffect011j.png");

	_animFrameCount = 0;
}

// �e����ʂɕ\������
void BulletStar::Render()
{
	// ���]�t���O��TRUE�ɂ��Ă���͉̂摜�̌����̊֌W��
	DrawRectGraph(static_cast<int>(_position.x),
		static_cast<int>(_position.y), _offset.x, _offset.y,
		static_cast<int>(_size.x),
		static_cast<int>(_size.y), grp, TRUE, TRUE);
}

// �㉺���E���]
void BulletStar::Reverse(int x, int y) {
	_velocity.x *= x;
	_velocity.y *= y;
}

// �X�V
void BulletStar::Update()
{
	// �A�j���[�V�����̎��s
	_animFrameCount++;

	// �摜�̃I�t�Z�b�g�ʒu��ύX
	auto sheetNo = _animFrameCount / AnimationSpeed;
	_offset.x = (sheetNo%HorizonSheet)*_size.x;
	_offset.y = ((sheetNo / HorizonSheet) % VerticalSheet)*_size.y;

	// �e�̍��W���ړ�������

	_position += _velocity;

}

