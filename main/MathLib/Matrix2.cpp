#include "Matrix2.h"

Matrix2::Matrix2()
{
	m00 = 1, m10 = 0;
	m01 = 0, m11 = 1;
}

Matrix2::Matrix2(Matrix2& rhs)
{
	m00 = rhs.m00, m10 = rhs.m10;
	m01 = rhs.m01, m11 = rhs.m11;
}

Matrix2::Matrix2(float a_m00, float a_m01, float a_m10, float a_11)
{
	m00 = a_m00, m10 = a_m10;
	m01 = a_m01, m11 = a_11;
}

Matrix2::~Matrix2()
{
}

void Matrix2::rotateZ(float a_rad)
{
	Matrix2 rotateMat;
	rotateMat.setRotateZ(a_rad);

	*this = rotateMat * *this;
}

void Matrix2::setRotateZ(float a_rad)
{
	m00 = cos(a_rad);
	m10 = -sin(a_rad);
	m01 = sin(a_rad);
	m11 = cos(a_rad);
}

Vector2 Matrix2::operator*(const Vector2& rhs)
{
	Vector2 newVec;

	newVec.x = m00 * rhs.x + m10 * rhs.y;
	newVec.y = m01 * rhs.x + m11 * rhs.y;

	return newVec;
}

Matrix2 Matrix2::operator*(const Matrix2& rhs)
{
	Matrix2 newMat;
	newMat.m00 = m00*rhs.m00 + m01*rhs.m10;
	newMat.m01 = m00*rhs.m01 + m01*rhs.m11;
	newMat.m10 = m10*rhs.m00 + m11*rhs.m10;
	newMat.m11 = m10*rhs.m01 + m11*rhs.m11;

	return newMat;
}

Matrix2::operator float*()
{
	return &m00;
}
