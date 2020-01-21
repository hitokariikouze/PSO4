#pragma once
#include "DxLib.h"
#include "Vector2D.h"
//	衝突判定クラス
class Collision
{
public:
	bool CircleCollision(const Vector2D& a, int aradius,
		const Vector2D& b, int bradius);
	//	矩形対矩形の判定
	bool RectCollision(const Vector2D& a,const Vector2D& asize,
		const Vector2D& b,const Vector2D& bsize);

	Vector2D GetDistance(Vector2D pos, float radius, Vector2D pos2, float radius2);

	bool CircleCollider(Vector2D pos, float radius, Vector2D pos2, float radius2);

	bool ColorCollider(Vector2D pos, float radius, Vector2D pos2, float radius2,int type1,int type2);
	int TypeCol(int type1, int type2);

};

