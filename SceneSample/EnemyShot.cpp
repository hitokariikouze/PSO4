#include "EnemyShot.h"

EnemyShot::~EnemyShot()
{
	// �������
	for (auto shot : _shotList) {
		delete shot;
	}
}

void EnemyShot::EShot(const Vector2D & pos)
{
}

void EnemyShot::EShot(const Vector2D & pos, float angle,float velocity)
{
	// �e�𓮓I�ɐ�������
	EnemyBullet* shot = new EnemyBullet(pos, angle,velocity);

	// �e�̏�����
	shot->Start();

	// �e�����X�g�Ɋi�[����
	_shotList.push_back(shot);
	
}

void EnemyShot::Update()
{
	// �C�e���[�^���g�p���đS�Ă̒e������
	for (auto it = _shotList.begin(); it != _shotList.end();)
	{
		// �e���X�V
		(*it)->Update();
		if ((*it)->Position().x < -30 || (*it)->Position().x > 480 ||
			(*it)->Position().y < 0 || (*it)->Position().y > 600 || 
			(*it)->endflag == true) {
			// �e������
			delete *it;
			it = _shotList.erase(it);
			continue;
		}
		// ���̃C�e���[�^���Q��
		++it;
	}
}

void EnemyShot::Render()
{
	for (auto shot : _shotList)
	{
		shot->Render();
	}
}
