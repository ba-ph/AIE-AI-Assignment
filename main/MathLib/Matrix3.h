#pragma once
#include "Vector2.h"
#include "Vector3.h"
class Matrix3
{
public:
	union
	{
		float m[9];
		struct
		{
			float m00, m10, m20;
			float m01, m11, m21;
			float m02, m12, m22;
		};
	};

	Matrix3();
	Matrix3(Matrix3& rhs);
	Matrix3(float a_00, float a_10, float a_20,
		    float a_01, float a_11, float a_21,
		    float a_02, float a_12, float a_22);
	~Matrix3();

	static Matrix3 CreateIdentity();
	Matrix3& Transpose(); //Returns *this
	Matrix3 GetTranspose();

	// V = M x V
	Vector2 operator*(const Vector2& rhs) const;
	Vector3 operator*(const Vector3& rhs) const;

	// M = M x M
	Matrix3 operator*(const Matrix3& rhs);


	//extra
	Vector2 GetPos();

	operator float*();

	void setRotationX(float a_rad);
	void setRotationY(float a_rad);
	void setRotationZ(float a_rad);

   Matrix3& operator=(Matrix3& rhs);

};

