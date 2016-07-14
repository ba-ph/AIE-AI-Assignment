#pragma once
#include <math.h>
class Vector4
{
public:
	Vector4();
	Vector4(Vector4& rhs);
	Vector4(float a_x, float a_y, float a_z, float a_w);
	~Vector4();

	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};

	// V  = V + V (Use the w for the lhs)
	Vector4 operator+(const Vector4& rhs) const;
	// V = V - V (Use the w for the lhs)
	Vector4  operator-(const Vector4& rhs) const;
	// V = V * f (Use the w for the lhs)
	Vector4 operator*(float rhs) const;
	//Use the w for the lhs
	Vector4 Cross(const Vector4& rhs) const;
	//Ignore the w
	float Dot(Vector4& rhs);
	//ignore the w
	float Magnitude();
	//ignore the w
	void Normalise();
	Vector4 Normalized();

	//Case operator
	operator float*();

	void operator+=(Vector4& rhs);
	bool operator==(Vector4& rhs);
	Vector4 operator*(Vector4& rhs);
};

// V = f * V (Use the w for the lhs)
Vector4 operator*(float a_lhs, const Vector4& rhs);

