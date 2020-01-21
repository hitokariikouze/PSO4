#pragma once
#include "WindowInfo.h"
#include "Vector2D.h"
#include "DxLib.h"

class StarDot {
public:
	StarDot(Vector2D pos);

	~StarDot();

	void Update();

	void Render();
private:
	Vector2D _position;
	Vector2D _size;
	Vector2D _velocity;
};