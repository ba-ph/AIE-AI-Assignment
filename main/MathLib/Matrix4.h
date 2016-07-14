#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
class Matrix4
{
public:
	Matrix4();
	Matrix4(float a_00, float a_10, float a_20, float a_30,
		    float a_01, float a_11, float a_21, float a_31,
		    float a_02, float a_12, float a_22, float a_32,
		    float a_03, float a_13, float a_23, float a_33);
	Matrix4(Matrix4& rhs);
	~Matrix4();
	union
	{
		float m[16];
		struct
		{
			float m00, m10, m20, m30;
			float m01, m11, m21, m31;
			float m02, m12, m22, m32;
			float m03, m13, m23, m33;
		};
	};

	operator float*();

	static Matrix4 CreateIdentity();
	Matrix4& Transpose(); //Returns *this
	Matrix4 GetTranspose();
	void Translate(const Vector3 a_translation);
	void SetTranslate(const Vector3 a_translation);

	// V = M x V
	Vector4 operator*(const Vector4& rhs) const;

	// Need to implement these
	void setRotationX(float a_rad);
	void setRotationY(float a_rad);
	void setRotationZ(float a_rad);

	Matrix4& operator=(Matrix4& rhs);
	Matrix4 operator*(Matrix4& rhs);
};

