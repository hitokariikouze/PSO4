#include "Vector2D.h"
//	�R���X�g���N�^
Vector2D::Vector2D() :x(0), y(0) {
}

//	�����t���R���X�g���N�^
Vector2D::Vector2D(float x, float y) : x(x), y(y) {
}

//	���Z�q�I�[�o�[���[�h�u+�v
Vector2D Vector2D::operator + (const Vector2D& vec) {

	Vector2D t(this->x + vec.x, this->y + vec.y);

	return t;
}

//	���Z�q�I�[�o�[���[�h�u+=�v
Vector2D& Vector2D::operator += (const Vector2D& vec) {
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}


//	���Z�q�I�[�o�[���[�h�u-�v
Vector2D Vector2D::operator - (const Vector2D& vec) {

	Vector2D t(this->x - vec.x, this->y - vec.y);

	return t;
}

//	���Z�q�I�[�o�[���[�h�u-=�v
Vector2D& Vector2D::operator -= (const Vector2D& vec) {
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vector2D Vector2D::operator*(const float & scale)
{
	Vector2D t(this->x * scale, this->y * scale);

	return t;
}
//	�x�N�g���̓���
float Vector2D::Dot(const Vector2D& vec)
{
	return (x * vec.x) + (y * vec.y);
}

//	�x�N�g���̊O��
float Vector2D::Cross(const Vector2D& vec)
{
	return (x * vec.y) - (y * vec.x);
}

//	�x�N�g���̒����擾
float Vector2D::Magnitude()
{
	return static_cast<float>(sqrt(x * x + y * y));
}

//	�x�N�g���̐��K��
Vector2D Vector2D::Normalized()
{
	return{ x / Magnitude() , y / Magnitude() };
}