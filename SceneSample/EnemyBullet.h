#pragma once
#pragma once
#include "Vector2D.h"
#include "DxLib.h"

// �e�̃N���X
class EnemyBullet
{
public:

	EnemyBullet(Vector2D pos, float angle,float velocity);

	// �f�X�g���N�^
	~EnemyBullet();

	// �J�n
	void Start();

	// �`��
	void Render();

	// �X�V
	void Update();


	// ���W�̍X�V
	Vector2D Position() {
		return _position;
	}

	// �T�C�Y�̎擾
	Vector2D Size() {
		return _size;
	}
	bool endflag;

private:
	const int AnimationSpeed = 4; // �A�j���[�V�����̑��x
	const int HorizonSheet = 5; // ���摜�̖���
	const int VerticalSheet = 4; // �c�摜�̖���
	Vector2D _position; // ���W
	Vector2D _size; // �摜�T�C�Y
	Vector2D _offset; // �I�t�Z�b�g���W
	Vector2D _velocity; // ���x
	int grp; // �摜ID
	int _animFrameCount; // �A�j���[�V�����̃t���[���J�E���g
};