#include "PlayerShot.h"

// �f�X�g���N�^
PlayerShot::~PlayerShot()
{
	// �������
	for (auto shot : _shotList) {
		delete shot;
	}
}

// �e�𔭎˂���
void PlayerShot::Shot(const Vector2D& pos)
{
	// �e�𓮓I�ɐ�������
	BulletStar* shot = new BulletStar(pos);

	// �e�̏�����
	shot->Start();

	// �e�����X�g�Ɋi�[����
	_shotList.push_back(shot);
}

// �e�𔭎˂���
void PlayerShot::Shot(const Vector2D& pos, float angle)
{
	// �e�𓮓I�ɐ�������
	BulletStar* shot = new BulletStar(pos, angle);

	// �e�̏�����
	shot->Start();

	// �e�����X�g�Ɋi�[����
	_shotList.push_back(shot);
}

// �������X�V����
void PlayerShot::Update()
{
	// �C�e���[�^���g�p���đS�Ă̒e������
	for (auto it = _shotList.begin(); it != _shotList.end();)
	{
		// �e���X�V
		(*it)->Update();

		// �e���E��ʒ[���z������
		if ((*it)->Position().x + 32 > WindowInfo::WindowWidth) {
			(*it)->Reverse(-1, 1);
		}
		else if ((*it)->Position().x < 0) {
			(*it)->Reverse(-1, 1);
		}
		if ((*it)->Position().y < 0) {
			// �e������
			delete *it;
			it = _shotList.erase(it);
			continue;
		}
		// ���̃C�e���[�^���Q��
		++it;
	}
}

// �e����ʂɕ\������
void PlayerShot::Render()
{
	for (auto shot : _shotList)
	{
		shot->Render();
	}
}