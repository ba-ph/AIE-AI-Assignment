#include "Vector4.h"



Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(Vector4 & rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
}

Vector4::Vector4(float a_x, float a_y, float a_z, float a_w)
{
	x = a_x;
	y = a_y;
	z = a_z;
	w = a_w;
}


Vector4::~Vector4()
{
}

Vector4 Vector4::operator+(const Vector4 & rhs) const
{
	Vector4 newVec;
	newVec.x = x + rhs.x;
	newVec.y = y + rhs.y;
	newVec.z = z + rhs.z;
	newVec.w = rhs.w;
	return newVec;
}

Vector4 Vector4::operator-(const Vector4 & rhs) const
{
	Vector4 newVec;
	newVec.x = x - rhs.x;
	newVec.y = y - rhs.y;
	newVec.z = z - rhs.z;
	newVec.w = w - rhs.w;
	return newVec;
}

Vector4 Vector4::operator*(float rhs) const
{
	Vector4 newVec;
	newVec.x = x * rhs;
	newVec.y = y * rhs;
	newVec.z = z * rhs;
	newVec.w = 0;
	return newVec;
}

Vector4 Vector4::Cross(const Vector4 & rhs) const
{
	Vector4 crossVec(y * rhs.z - z * rhs.y, z *rhs.x - rhs.z * x, x * rhs.y - y * rhs.x, 0);
	return crossVec; //.Normalized();
}

float Vector4::Dot(Vector4 & rhs)
{
	return this->x * rhs.x + this->y*rhs.y + this->z * rhs.z;
}

float Vector4::Magnitude()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector4::Normalise()
{
	float magnitude = Magnitude();

	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
	//w = w / magnitude;
}

Vector4 Vector4::Normalized()
{
	Vector4 normedVec;

	float magnitude = Magnitude();

	normedVec.x = x / magnitude;
	normedVec.y = y / magnitude;
	normedVec.z = z / magnitude;
	//normedVec.w = w / magnitude;
	return normedVec;
}

Vector4::operator float*()
{
	return &x;
}

void Vector4::operator+=(Vector4 & rhs)
{
	x = x + rhs.x;
	y = y + rhs.y;
	z = z + rhs.z;
	w = rhs.w;
}

bool Vector4::operator==(Vector4 & rhs)
{
	if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
	{
		return true;
	}
	return false;
}

Vector4 Vector4::operator*(Vector4 & rhs)
{
	Vector4 newVec;
	newVec.x = x * rhs.x;
	newVec.y = y * rhs.y;
	newVec.z = z * rhs.z;
	newVec.w = w * rhs.w;
	return newVec;
}


Vector4 operator*(float a_lhs, const Vector4 & rhs)
{
	return rhs*a_lhs;
}
