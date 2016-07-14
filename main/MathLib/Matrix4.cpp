#include "Matrix4.h"



Matrix4::Matrix4()
{
	m00 = 1, m10 = 0, m20 = 0, m30 = 0;
	m01 = 0, m11 = 1, m21 = 0, m31 = 0;
	m02 = 0, m12 = 0, m22 = 1, m32 = 0;
	m03 = 0, m13 = 0, m23 = 0, m33 = 1;
}

Matrix4::Matrix4(float a_00, float a_10, float a_20, float a_30,
	             float a_01, float a_11, float a_21, float a_31,
	             float a_02, float a_12, float a_22, float a_32,
	             float a_03, float a_13, float a_23, float a_33)
{
	m00 = a_00, m10 = a_10, m20 = a_20, m30 = a_30;
	m01 = a_01, m11 = a_11, m21 = a_21, m31 = a_31;
	m02 = a_02, m12 = a_12, m22 = a_22, m32 = a_32;
	m03 = a_03, m13 = a_13, m23 = a_23, m33 = a_33;
}

Matrix4::Matrix4(Matrix4 & rhs)
{
	m00 = rhs.m00, m10 = rhs.m10, m20 = rhs.m20, m30 = rhs.m30;
	m01 = rhs.m01, m11 = rhs.m11, m21 = rhs.m21, m31 = rhs.m31;
	m02 = rhs.m02, m12 = rhs.m12, m22 = rhs.m22, m32 = rhs.m32;
	m03 = rhs.m03, m13 = rhs.m13, m23 = rhs.m23, m33 = rhs.m33;
}


Matrix4::~Matrix4()
{

}

Matrix4::operator float*()
{
	return &m00;
}

Matrix4 Matrix4::CreateIdentity()
{
	Matrix4 identMatrix;
	return identMatrix;
}

void Matrix4::Translate(const Vector3 a_translation)
{
	Matrix4 translationMatrix;
	translationMatrix.SetTranslate(a_translation);

	*this = translationMatrix * *this;
}

void Matrix4::SetTranslate(const Vector3 a_translation)
{
	m03 = a_translation.x;
	m13 = a_translation.y;
}

Vector4 Matrix4::operator*(const Vector4& rhs) const
{
	Vector4 newVec;

	/*newVec.x = m00 * rhs.x + m10 * rhs.y + m20 * rhs.z + m30 * rhs.w;
	newVec.y = m01 * rhs.x + m11 * rhs.y + m21 * rhs.z + m31 * rhs.w;
	newVec.z = m02 * rhs.x + m12 * rhs.y + m22 * rhs.z + m32 * rhs.w;
	newVec.w = m03 * rhs.x + m13 * rhs.y + m33 * rhs.z + m33 * rhs.w;*/

	newVec.x = m[0] * rhs.x + m[4] * rhs.y + m[8]  * rhs.z + m[12] * rhs.w;
	newVec.y = m[1] * rhs.x + m[5] * rhs.y + m[9]  * rhs.z + m[13] * rhs.w;
	newVec.z = m[2] * rhs.x + m[6] * rhs.y + m[10] * rhs.z + m[14] * rhs.w;
	newVec.w = m[3] * rhs.x + m[7] * rhs.y + m[11] * rhs.z + m[15] * rhs.w;

	return newVec;
}

void Matrix4::setRotationX(float a_rad)
{
	m11 = cos(a_rad);
	m12 = -sin(a_rad);
	m21 = sin(a_rad);
	m22 = cos(a_rad);
}

void Matrix4::setRotationY(float a_rad)
{
	m00 = cos(a_rad);
	m02 = sin(a_rad);
	m20 = -sin(a_rad);
	m22 = cos(a_rad);
}

void Matrix4::setRotationZ(float a_rad)
{
	m00 = cos(a_rad);
	m01 = -sin(a_rad);
	m10 = sin(a_rad);
	m11 = cos(a_rad);
}

Matrix4 & Matrix4::operator=(Matrix4 & rhs)
{
	m00 = rhs.m00, m10 = rhs.m10, m20 = rhs.m20, m30 = rhs.m30;
	m01 = rhs.m01, m11 = rhs.m11, m21 = rhs.m21, m31 = rhs.m31;
	m02 = rhs.m02, m12 = rhs.m12, m22 = rhs.m22, m32 = rhs.m32;
	m03 = rhs.m03, m13 = rhs.m13, m23 = rhs.m23, m33 = rhs.m33;

	return *this;
}

Matrix4 Matrix4::operator*(Matrix4 & rhs)
{
	Matrix4 newMat;

	newMat.m00 = m00*rhs.m00 + m01*rhs.m10 + m02*rhs.m20 + m03*rhs.m30;
	newMat.m01 = m00*rhs.m01 + m01*rhs.m11 + m02*rhs.m21 + m03*rhs.m31;    
	newMat.m02 = m00*rhs.m02 + m01*rhs.m12 + m02*rhs.m22 + m03*rhs.m32;    
	newMat.m03 = m00*rhs.m03 + m01*rhs.m13 + m02*rhs.m23 + m03*rhs.m33;    

	newMat.m10 = m10*rhs.m00 + m11*rhs.m10 + m12*rhs.m20 + m13*rhs.m30;
	newMat.m11 = m10*rhs.m01 + m11*rhs.m11 + m12*rhs.m21 + m13*rhs.m31;
	newMat.m12 = m10*rhs.m02 + m11*rhs.m12 + m12*rhs.m22 + m13*rhs.m32;
	newMat.m13 = m10*rhs.m03 + m11*rhs.m13 + m12*rhs.m23 + m13*rhs.m33;

	newMat.m20 = m20*rhs.m00 + m21*rhs.m10 + m22*rhs.m20 + m23*rhs.m30;
	newMat.m21 = m20*rhs.m01 + m21*rhs.m11 + m22*rhs.m21 + m23*rhs.m31;
	newMat.m22 = m20*rhs.m02 + m21*rhs.m12 + m22*rhs.m22 + m23*rhs.m32;
	newMat.m23 = m20*rhs.m03 + m21*rhs.m13 + m22*rhs.m23 + m23*rhs.m33;

	newMat.m30 = m30*rhs.m00 + m31*rhs.m10 + m32*rhs.m20 + m33*rhs.m30;
	newMat.m31 = m30*rhs.m01 + m31*rhs.m11 + m32*rhs.m21 + m33*rhs.m31;
	newMat.m32 = m30*rhs.m02 + m31*rhs.m12 + m32*rhs.m22 + m33*rhs.m32;
	newMat.m33 = m30*rhs.m03 + m31*rhs.m13 + m32*rhs.m23 + m33*rhs.m33;

	return newMat;
}
