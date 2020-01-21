#include "StarDot.h"

StarDot::StarDot(Vector2D pos) :_position(pos), _size(Vector2D(8, 8))
{
	_velocity = Vector2D(0, 1);
}

StarDot::~StarDot()
{
}

void StarDot::Update()
{
	_position += _velocity;
}

void StarDot::Render()
{
	DrawBox(_position.x, _position.y, _position.x + _size.x, _position.y + _size.y, GetColor(100, 100, 100), TRUE);
}
