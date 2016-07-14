#pragma once
#include "Vector2.h"
class Matrix2
{
public:
	Matrix2();
	Matrix2(Matrix2& rhs);
	//Pass into function in column order
	Matrix2(float a_m00, float a_m01, float a_m10, float a_11);
	~Matrix2();

	union
	{
		float m[4];
		struct
		{
			float m00, m10;
			float m01, m11;
		};
	};

	//Cast Operator
	operator float*();

	// V = M x V
	Vector2 operator*(const Vector2& rhs);
	// M = M x M
	Matrix2 operator*(const Matrix2& rhs);

	//Set rotation
	void rotateZ(float a_rad);
	void setRotateZ(float a_rad);
};