#include "Vector2.h"



Vector2::Vector2()
{
	x = 0;
	y = 0;
}
Vector2::Vector2(Vector2 & rhs)
{
	x = rhs.x;
	y = rhs.y;
}
Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}
Vector2::Vector2(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;
}
Vector2::~Vector2()
{

}

Vector2 Vector2::operator+(const Vector2 rhs) const
{
		Vector2 vec;
		vec.x = x + rhs.x;
		vec.y = y + rhs.y;
		return vec;
}
Vector2 Vector2::operator-(const Vector2 & rhs) const
{
	Vector2 vec3;

	vec3.x = x - rhs.x;
	vec3.y = y - rhs.y;

	return vec3;
}
Vector2 Vector2::operator*(float rhs) const
{
	Vector2 vec3;

	vec3.x = x* rhs;
	vec3.y = y* rhs;

	return vec3;
}
Vector2 Vector2::operator*(Vector2 & rhs)
{
	Vector2 vec3;

	vec3.x = x * rhs.x;
	vec3.y = y * rhs.y;

	return vec3;
}
void Vector2::operator+=(Vector2 & rhs)
{
	x = x + rhs.x;
	y = y + rhs.y;
}
bool Vector2::operator==(Vector2 & rhs)
{
	if (x == rhs.x && y == rhs.y)
	{
		return true;
	}
	return false;
}
Vector2::operator float*()
{
	return &x;
}

float Vector2::Dot(const Vector2 & rhs) const
{
	return this->x * rhs.x + this->y*rhs.y;
}
float Vector2::Magnitude() const
{
	return sqrt(x*x + y*y);
}

void Vector2::Normalise()
{
	float magnitude = Magnitude();

	x = x / magnitude;
	y = y / magnitude;
}

Vector2 Vector2::Normalized()
{
	Vector2 normedVec;

	float magnitude = Magnitude();

	normedVec.x = x / magnitude;
	normedVec.y = y / magnitude;

	return normedVec;
}

Vector2 Vector2::perpendicular(Vector2 & rhs)
{
	Vector2 perp(-rhs.y, rhs.x);
	return perp;
}

float Vector2::Distance(Vector2 a_pos1, Vector2 a_pos2)
{
	float m_distanceX = (a_pos1.x - a_pos2.x) * (a_pos1.x - a_pos2.x);
	float m_distanceY = (a_pos1.y - a_pos2.y) * (a_pos1.y - a_pos2.y);

	return sqrt(m_distanceX + m_distanceY);
}
float Vector2::Distance(float a_pos1X, float a_pos1Y, float a_pos2X, float a_pos2Y)
{
	float m_distanceX = (a_pos1X - a_pos2X) * (a_pos1X - a_pos2X);
	float m_distanceY = (a_pos1Y - a_pos2Y) * (a_pos1Y - a_pos2Y);
	return sqrt(m_distanceX + m_distanceY);
}
float Vector2::SqrDistance(Vector2 a_pos1, Vector2 a_pos2)
{
	float m_distanceX = (a_pos1.x - a_pos2.x) * (a_pos1.x - a_pos2.x);
	float m_distanceY = (a_pos1.y - a_pos2.y) * (a_pos1.y - a_pos2.y);

	return m_distanceX + m_distanceY;
}

//V = f * V
Vector2 operator*(float a_lhs, const Vector2 & rhs)
{
	return rhs*a_lhs;
}
