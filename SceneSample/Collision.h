#pragma once
#include "Vector2D.h"
//	�Փ˔���N���X
class Collision
{
public:
	bool CircleCollision(const Vector2D& a, int aradius,
		const Vector2D& b, int bradius);
	//	��`�΋�`�̔���
	bool RectCollision(const Vector2D& a,const Vector2D& asize,
		const Vector2D& b,const Vector2D& bsize);

};

