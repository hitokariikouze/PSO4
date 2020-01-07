#include "Collision.h"
#include <cmath>



//	‹éŒ`‘Î‹éŒ`‚Ì”»’è

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
