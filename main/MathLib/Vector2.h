//////////
// Author: James Creaton
// Last Edited: 27/5/2016
///////////
#pragma once
#include <math.h>
class Vector2
{
public:
	Vector2();
	Vector2(Vector2& rhs);
	Vector2(const Vector2& rhs);
	Vector2(float a_x, float a_y);
	~Vector2();

	union
	{
		struct
		{
			float x;
			float y;
		};
	};

	// V = V + V
	Vector2 operator+(const Vector2 rhs) const;
	// V = V - V
	Vector2 operator-(const Vector2& rhs) const;
	// V = V * f
	Vector2 operator*(float rhs) const;

	float Dot(const Vector2& rhs) const;
	float Magnitude() const;
	float SqaureMagnitude() const;
	void Normalise();
	Vector2 Normalized();

	//Case operator
	operator float*();

	
	void operator+=(Vector2& rhs);
	Vector2 operator*(Vector2& rhs);
	Vector2 operator-(float& rhs);
	bool operator==(Vector2& rhs);

	Vector2 perpendicular(Vector2& rhs);

	//Distance between two vectors using square root
	float Vector2::Distance(Vector2 a_pos);
	float Vector2::Distance(Vector2 a_pos1, Vector2 a_pos2);
	//Distance between two float sets using square root
	float Vector2::Distance(float a_pos1X, float a_pos1Y, float a_pos2X, float a_pos2Y);
	//Distance between two vectors not using square root
	float Vector2::SqrDistance(Vector2 a_pos1, Vector2 a_pos2);
	float Vector2::SqrDistance(Vector2& rhs);
};

Vector2 operator*(float a_lhs, const Vector2& rhs);


 