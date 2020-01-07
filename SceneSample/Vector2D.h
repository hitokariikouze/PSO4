#pragma once
#include <cmath>

// Vector2Dクラス
class Vector2D {

public:
	//	デフォルトコンストラクタ
	Vector2D();

	//	引数付きコンストラクタ
	Vector2D(float x, float y);

	//	演算子オーバーロード「+」
	Vector2D operator + (const Vector2D& vec);

	//	演算子オーバーロード「+=」
	Vector2D& operator += (const Vector2D& vec);

	//	演算子オーバーロード「-」
	Vector2D operator - (const Vector2D& vec);

	//	演算子オーバーロード「-=」
	Vector2D& operator -= (const Vector2D& vec);

	//	演算子オーバーロード「*」
	Vector2D operator*(const float & scale);

	//	ベクトルの内積
	float Dot(const Vector2D& vec);

	//	ベクトルの外積
	float Cross(const Vector2D& vec);

	//	ベクトルの長さ取得
	float Magnitude();

	//	ベクトルの正規化
	Vector2D Normalized();

public:
	float x;
	float y;
};