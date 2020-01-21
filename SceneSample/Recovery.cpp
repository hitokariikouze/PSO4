#include "DxLib.h"
#include "Recovery.h"

Recovery::Recovery(Vector2D pos) : _position(pos), _size(Vector2D(32, 32))
{
}

void Recovery::Start() {

}

void Recovery::Update() {

}

void Recovery::Render() {
	DrawBox(_position.x, _position.y, _size.x, _size.y, GetColor(250, 250, 250), false);
}

Recovery::~Recovery()
{
}