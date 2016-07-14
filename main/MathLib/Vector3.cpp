#include "Vector3.h"



Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}
Vector3::Vector3(Vector3 & rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}
Vector3::Vector3(const Vector3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}
Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}
Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(const Vector3 & rhs) const
{
	Vector3 newVec;
	newVec.x = x + rhs.x;
	newVec.y = y + rhs.y;
	newVec.z = z + rhs.z;
	return newVec;
}
Vector3 Vector3::operator-(const Vector3 & rhs) const
{
	Vector3 newVec;
	newVec.x = x - rhs.x;
	newVec.y = y - rhs.y;
	newVec.z = z - rhs.z;
	return newVec;
}
Vector3 Vector3::operator*(float rhs) const
{
	Vector3 newVec;
	newVec.x = x * rhs;
	newVec.y = y * rhs;
	newVec.z = z * rhs;
	return newVec;
}

Vector3::operator float*()
{
	return &x;
}

float Vector3::Dot(const Vector3 & rhs) const
{
	return this->x * rhs.x + this->y*rhs.y + this->z * rhs.z;
}

Vector3 Vector3::Cross(const Vector3 & rhs) const
{
	Vector3 crossVec(y * rhs.z - z * rhs.y, z *rhs.x - rhs.z * x, x * rhs.y - y * rhs.x);
	return crossVec; //.Normalized();
}

float Vector3::Magnitude()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector3::Normalise()
{
	float magnitude = Magnitude();

	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
}

Vector3 Vector3::Normalized()
{
	Vector3 normedVec;

	float magnitude = Magnitude();

	normedVec.x = x / magnitude;
	normedVec.y = y / magnitude;
	normedVec.z = z / magnitude;

	return normedVec;
}

void Vector3::operator+=(Vector3 & rhs)
{
	x = x + rhs.x;
	y = y + rhs.y;
	z = z + rhs.z;
}

bool Vector3::operator==(Vector3 & rhs)
{
	if (x == rhs.x && y == rhs.y && z == rhs.z)
	{
		return true;
	}
	return false;
}

Vector3 Vector3::operator*(Vector3 & rhs)
{
	Vector3 newVec;
	newVec.x = x * rhs.x;
	newVec.y = y * rhs.y;
	newVec.z = z * rhs.z;
	return newVec;
}

Vector3 operator*(float a_lhs, const Vector3 & rhs)
{
	return rhs*a_lhs;
}
