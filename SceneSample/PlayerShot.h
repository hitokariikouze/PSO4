#pragma once
#include <list>
#include "Vector2D.h"
#include "BulletStar.h"
#include "WindowInfo.h"

// �e�����N���X
class PlayerShot
{
public:
	// �f�X�g���N�^
	~PlayerShot();

	// �e������
	void Shot(const Vector2D& pos);
	void Shot(const Vector2D& pos, float angle);

	// �����̍X�V
	void Update();

	// �`��
	void Render();

public:
	std::list<BulletStar*> _shotList; // �e���X�g
};
