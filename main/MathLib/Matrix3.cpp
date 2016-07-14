#include "Matrix3.h"



Matrix3::Matrix3()
{
	m00 = 1; m10 = 0; m20 = 0;
	m01 = 0; m11 = 1; m21 = 0;
	m02 = 0; m12 = 0; m22 = 1;
}

Matrix3::Matrix3(Matrix3 & rhs)
{
	m00 = rhs.m00; m10 = rhs.m10; m20 = rhs.m20;
	m01 = rhs.m01; m11 = rhs.m11; m21 = rhs.m21;
	m02 = rhs.m02; m12 = rhs.m12; m22 = rhs.m22;
}

Matrix3::Matrix3(float a_00, float a_01, float a_02, float a_10, float a_11, float a_12, float a_20, float a_21, float a_22)
{
	m00 = a_00; m10 = a_10; m20 = a_20;
	m01 = a_01; m11 = a_11; m21 = a_21;
	m02 = a_02; m12 = a_12; m22 = a_22;
}


Matrix3::~Matrix3()
{
}

Matrix3 Matrix3::CreateIdentity()
{
	Matrix3 identMatrix;

	identMatrix.m00 = 1, identMatrix.m10 = 0; identMatrix.m20 = 0;
	identMatrix.m01 = 0; identMatrix.m11 = 1; identMatrix.m21 = 0;
	identMatrix.m02 = 0; identMatrix.m12 = 0; identMatrix.m22 = 1;

	return identMatrix;
}

Matrix3 & Matrix3::Transpose()
{
	return *this;

	// TODO: insert return statement here
}

Matrix3 Matrix3::GetTranspose()
{
	return Matrix3();
}

Vector2 Matrix3::operator*(const Vector2 & rhs) const
{
	Vector2 newVec;

	/*newVec.x = m00 * rhs.x + m10 * rhs.y + m20 * rhs.z;
	newVec.y = m01 * rhs.x + m11 * rhs.y + m21 * rhs.z;
	newVec.z = m02 * rhs.x + m12 * rhs.y + m22 * rhs.z;*/

	return newVec;
}

Vector3 Matrix3::operator*(const Vector3& rhs) const
{
	Vector3 newVec;

	newVec.x = m00 * rhs.x + m10 * rhs.y + m20 * rhs.z;
	newVec.y = m01 * rhs.x + m11 * rhs.y + m21 * rhs.z;
	newVec.z = m02 * rhs.x + m12 * rhs.y + m22 * rhs.z;

	return newVec;
}

Matrix3 Matrix3::operator*(const Matrix3 & rhs)
{
	Matrix3 newMat;

	newMat.m00 = m00*rhs.m00 + m10*rhs.m01 + m20*rhs.m02;
	newMat.m01 = m01*rhs.m00 + m11*rhs.m01 + m21*rhs.m02;
	newMat.m02 = m02*rhs.m00 + m12*rhs.m01 + m22*rhs.m02;

	newMat.m10 = m00*rhs.m10 + m10*rhs.m11 + m20*rhs.m12;
	newMat.m11 = m01*rhs.m10 + m11*rhs.m11 + m12*rhs.m21;
	newMat.m12 = m02*rhs.m10 + m12*rhs.m11 + m22*rhs.m12;

	newMat.m20 = m00*rhs.m20 + m10*rhs.m21 + m20*rhs.m22;
	newMat.m21 = m01*rhs.m20 + m11*rhs.m21 + m21*rhs.m22;
	newMat.m22 = m02*rhs.m20 + m12*rhs.m21 + m22*rhs.m22;

	return newMat;
}

Vector2 Matrix3::GetPos()
{
	return Vector2(m02, m12);
}

Matrix3::operator float*()
{
		return &m00;
}

void Matrix3::setRotationX(float a_rad)
{
	m11 = cos(a_rad);
	m21 = -sin(a_rad);
	m12 = sin(a_rad);
	m22 = cos(a_rad);
}

void Matrix3::setRotationY(float a_rad)
{
	m00 = cos(a_rad);
	m20 = sin(a_rad);
	m02 = -sin(a_rad);
	m22 = cos(a_rad);
}

void Matrix3::setRotationZ(float a_rad)
{
	m00 = cos(a_rad);
	m10 = -sin(a_rad);
	m01 = sin(a_rad);
	m11 = cos(a_rad);
}

Matrix3 & Matrix3::operator=(Matrix3 & rhs)
{
		m00 = rhs.m00, m10 = rhs.m10, m20 = rhs.m20;
		m01 = rhs.m01, m11 = rhs.m11, m21 = rhs.m21;
		m02 = rhs.m02, m12 = rhs.m12, m22 = rhs.m22;

		return *this;
}
