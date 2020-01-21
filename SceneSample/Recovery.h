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
	Vector2D _position; // ���W
	Vector2D _size; // �T�C�Y
};
