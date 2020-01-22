#include "EnemyBullet.h"
#define _USE_MATH_DEFINES // M_PI���g�p���邽��
#include <math.h>

EnemyBullet::EnemyBullet(Vector2D pos, float angle, float velocity) : _position(pos), _size(Vector2D(32, 32))
{
	// ���W�A���p�ɕϊ����n��
	auto x = cos((M_PI / 180)*angle)*velocity;
	auto y = sin((M_PI / 180)*angle)*velocity;

	_velocity = Vector2D(x, y);
}

EnemyBullet::~EnemyBullet()
{
	// �摜���J������
	DeleteGraph(grp);
}

void EnemyBullet::Start()
{
	// �摜�̓ǂݍ��݂��s��
	grp = LoadGraph("img\\EB.png");

	_animFrameCount = 0;
	endflag = false;
}

void EnemyBullet::Render()
{
	// ���]�t���O��TRUE�ɂ��Ă���͉̂摜�̌����̊֌W��

	DrawGraph(_position.x, _position.y, grp, TRUE);
}

void EnemyBullet::Update()
{
	// �e�̍��W���ړ�������

	_position += _velocity;
}
