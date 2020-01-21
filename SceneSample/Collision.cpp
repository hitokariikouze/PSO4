#include "Collision.h"
#include <cmath>



//	矩形対矩形の判定

bool Collision::CircleCollision(const Vector2D & a, int aradius, const Vector2D & b, int bradius)
{
	auto fx = abs((a.x + aradius) - (b.x + bradius));
	auto fy = abs((a.y + aradius) - (b.y + bradius));
	
		if ((fx * fx + fy * fy) <= (aradius + aradius) * (bradius + bradius))
		{
			return true;
		}
		return false;
}

bool Collision::RectCollision(const Vector2D & a, const Vector2D & asize, const Vector2D & b, const Vector2D & bsize)
{
	auto dx = abs((a.x + asize.x / 2) - (b.x + bsize.x / 2));
	auto dy = abs((a.y + asize.y/ 2) - (b.y + bsize.y / 2));
	
		if (dx < (asize.x + bsize.x) / 2 && dy < (asize.y + bsize.y) / 2)
		{
			return true;
		}
		return false;
}

Vector2D Collision::GetDistance(Vector2D pos, float radius, Vector2D pos2, float radius2)
{
	auto x = abs((pos2.x) - (pos.x));
	auto y = abs((pos2.y) - (pos.y));
	return Vector2D(((pos.x) + x / 2), ((pos.y) + y / 2));
}

bool Collision::CircleCollider(Vector2D pos, float radius, Vector2D pos2, float radius2)
{
	auto x = abs((pos2.x) - (pos.x));
	auto y = abs((pos2.y) - (pos.y));
	if ((x*x + y * y) <= (radius + radius2)*(radius + radius2)) {
		DrawString(0, 0, "ヒット", GetColor(255, 0, 0));
		return true;
	}
	return false;
}

bool Collision::ColorCollider(Vector2D pos, float radius, Vector2D pos2, float radius2, int type1,int type2)
{
	auto x = abs((pos2.x) - (pos.x));
	auto y = abs((pos2.y) - (pos.y));
	if ((x*x + y * y) <= (radius + radius2)*(radius + radius2) && type1 == type2) {
		DrawString(0, 0, "ヒット", GetColor(255, 0, 0));
		return true;
	}
	return false;
}

int Collision::TypeCol(int type1, int type2)
{
	if (type1 == type2)
	{
		return type1;
	}
	return false;
}
