#pragma once
#include <math.h>
class Vector3
{
public:
	Vector3();
	Vector3(Vector3& rhs);
	Vector3(const Vector3& rhs);
	Vector3(float a_x, float a_y, float a_z);
	~Vector3();

	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
	};

	// V = V + V
	Vector3 operator+(const Vector3& rhs) const;
	// V = V - V
	Vector3  operator-(const Vector3& rhs) const;
	// V = V * f
	Vector3 operator*(float rhs) const;

	operator float*();

	float Dot(const Vector3& rhs) const;
	Vector3 Cross(const Vector3& rhs) const;
	float Magnitude();
	void Normalise();
	Vector3 Normalized();
	
	void operator+=(Vector3& rhs);
	bool operator==(Vector3& rhs);
	Vector3 operator*(Vector3& rhs);
};

//V = f * V
Vector3 operator*(float a_lhs, const Vector3& rhs);

