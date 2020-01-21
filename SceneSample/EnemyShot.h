
#pragma once
#include <list>
#include "Vector2D.h"
#include "EnemyBullet.h"
#include "WindowInfo.h"

// �e�����N���X
class EnemyShot
{
public:
	// �f�X�g���N�^
	~EnemyShot();

	// �e������
	void EShot(const Vector2D& pos);
	void EShot(const Vector2D& pos, float angle,float velocity);

	// �����̍X�V
	void Update();

	// �`��
	void Render();

public:
	std::list<EnemyBullet*> _shotList; // �e���X�g
	
};