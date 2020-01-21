#pragma once
#include "Vector2D.h"

class Recovery
{
public:
	Recovery(Vector2D pos);

	void Start();

	void Update();

	void Render();

	Vector2D Position() {
		return _position;
	}

	Vector2D Size() {
		return _size;
	}

	bool hitflag;

	~Recovery();

private:
	Vector2D _position; // 座標
	Vector2D _size; // サイズ
};
