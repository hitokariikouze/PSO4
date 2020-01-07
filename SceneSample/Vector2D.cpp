#include "Vector2D.h"
//	コンストラクタ
Vector2D::Vector2D() :x(0), y(0) {
}

//	引数付きコンストラクタ
Vector2D::Vector2D(float x, float y) : x(x), y(y) {
}

//	演算子オーバーロード「+」
Vector2D Vector2D::operator + (const Vector2D& vec) {

	Vector2D t(this->x + vec.x, this->y + vec.y);

	return t;
}

//	演算子オーバーロード「+=」
Vector2D& Vector2D::operator += (const Vector2D& vec) {
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}


//	演算子オーバーロード「-」
Vector2D Vector2D::operator - (const Vector2D& vec) {

	Vector2D t(this->x - vec.x, this->y - vec.y);

	return t;
}

//	演算子オーバーロード「-=」
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
//	ベクトルの内積
float Vector2D::Dot(const Vector2D& vec)
{
	return (x * vec.x) + (y * vec.y);
}

//	ベクトルの外積
float Vector2D::Cross(const Vector2D& vec)
{
	return (x * vec.y) - (y * vec.x);
}

//	ベクトルの長さ取得
float Vector2D::Magnitude()
{
	return static_cast<float>(sqrt(x * x + y * y));
}

//	ベクトルの正規化
Vector2D Vector2D::Normalized()
{
	return{ x / Magnitude() , y / Magnitude() };
}
