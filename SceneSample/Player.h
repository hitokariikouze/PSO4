#pragma once
#include <DxLib.h>
#include "Vector2D.h"

// �v���C���[�N���X
class Player
{
public:
	// �R���X�g���N�^
	Player(Vector2D pos);
	~Player();

	// �J�n
	void Start();

	// �`��
	void Render();

	// �X�V
	void Update();

	// ���˃{�^������
	int OnShotButton();

	// �v���C���[�̃V���b�g�_���[�W
	int GetShotDamage();

	Vector2D Position() {
		return _position;
	}

	Vector2D Size() {
		return _size;
	}
	int hp;
	bool hitflag;
	bool onPulseFlag;
private:
	Vector2D _position; // ���W
	Vector2D _size; // �T�C�Y
	int grp; // �摜ID
	int linex, liney;
	int count;
	bool shotFlag;

	float timer;

};
