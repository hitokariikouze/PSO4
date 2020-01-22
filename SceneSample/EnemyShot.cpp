#include "EnemyShot.h"

EnemyShot::~EnemyShot()
{
	// ‰ð•ú‚·‚é
	for (auto shot : _shotList) {
		delete shot;
	}
}

void EnemyShot::EShot(const Vector2D & pos)
{
}

void EnemyShot::EShot(const Vector2D & pos, float angle,float velocity)
{
	// ’e‚ð“®“I‚É¶¬‚·‚é
	EnemyBullet* shot = new EnemyBullet(pos, angle,velocity);

	// ’e‚Ì‰Šú‰»
	shot->Start();

	// ’e‚ðƒŠƒXƒg‚ÉŠi”[‚·‚é
	_shotList.push_back(shot);
	
}

void EnemyShot::Update()
{
	// ƒCƒeƒŒ[ƒ^‚ðŽg—p‚µ‚Ä‘S‚Ä‚Ì’e‚ðˆ—
	for (auto it = _shotList.begin(); it != _shotList.end();)
	{
		// ’e‚ðXV
		(*it)->Update();
		if ((*it)->Position().x < -30 || (*it)->Position().x > 480 ||
			(*it)->Position().y < 0 || (*it)->Position().y > 600 || 
			(*it)->endflag == true) {
			// ’e‚ðÁ‚·
			delete *it;
			it = _shotList.erase(it);
			continue;
		}
		// ŽŸ‚ÌƒCƒeƒŒ[ƒ^‚ðŽQÆ
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
