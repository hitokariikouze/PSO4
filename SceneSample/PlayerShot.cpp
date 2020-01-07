#include "PlayerShot.h"

// ƒfƒXƒgƒ‰ƒNƒ^
PlayerShot::~PlayerShot()
{
	// ‰ð•ú‚·‚é
	for (auto shot : _shotList) {
		delete shot;
	}
}

// ’e‚ð”­ŽË‚·‚é
void PlayerShot::Shot(const Vector2D& pos)
{
	// ’e‚ð“®“I‚É¶¬‚·‚é
	BulletStar* shot = new BulletStar(pos);

	// ’e‚Ì‰Šú‰»
	shot->Start();

	// ’e‚ðƒŠƒXƒg‚ÉŠi”[‚·‚é
	_shotList.push_back(shot);
}

// ’e‚ð”­ŽË‚·‚é
void PlayerShot::Shot(const Vector2D& pos, float angle)
{
	// ’e‚ð“®“I‚É¶¬‚·‚é
	BulletStar* shot = new BulletStar(pos, angle);

	// ’e‚Ì‰Šú‰»
	shot->Start();

	// ’e‚ðƒŠƒXƒg‚ÉŠi”[‚·‚é
	_shotList.push_back(shot);
}

// ˆ—‚ðXV‚·‚é
void PlayerShot::Update()
{
	// ƒCƒeƒŒ[ƒ^‚ðŽg—p‚µ‚Ä‘S‚Ä‚Ì’e‚ðˆ—
	for (auto it = _shotList.begin(); it != _shotList.end();)
	{
		// ’e‚ðXV
		(*it)->Update();

		// ’e‚ª‰E‰æ–Ê’[‚ð‰z‚¦‚½‚ç
		if ((*it)->Position().x + 32 > WindowInfo::WindowWidth) {
			(*it)->Reverse(-1, 1);
		}
		else if ((*it)->Position().x < 0) {
			(*it)->Reverse(-1, 1);
		}
		if ((*it)->Position().y < 0) {
			// ’e‚ðÁ‚·
			delete *it;
			it = _shotList.erase(it);
			continue;
		}
		// ŽŸ‚ÌƒCƒeƒŒ[ƒ^‚ðŽQÆ
		++it;
	}
}

// ’e‚ð‰æ–Ê‚É•\Ž¦‚·‚é
void PlayerShot::Render()
{
	for (auto shot : _shotList)
	{
		shot->Render();
	}
}