#include "Transform.h"

Transform::Transform()
{
	m_parent = nullptr;
}
Transform::~Transform()
{

}

void Transform::SetScale(float a_scale, Matrix3& a_scaleMat)
{
	a_scaleMat.m00 =  a_scale;
	a_scaleMat.m11 =  a_scale;
}

void Transform::Scale(float a_scale)
{
	Matrix3 scaleMatrix;
	SetScale(a_scale, scaleMatrix);

	localMatrix = scaleMatrix * localMatrix;
}

void Transform::Translate(const Vector2 & a_translation)
{
	Matrix3 translationMatrix;
	SetTranslation(a_translation, translationMatrix);

	localMatrix =  translationMatrix * localMatrix;
}

void Transform::SetTranslation(const Vector2 & a_translation, Matrix3& a_translateMatrix)
{
	a_translateMatrix.m02 = a_translation.x;
	a_translateMatrix.m12 = a_translation.y;
}

void Transform::SetTranslationLocal(const Vector2 & a_translation)
{
	localMatrix.m02 = a_translation.x;
	localMatrix.m12 = a_translation.y;
}

void Transform::Rotate(float a_rad)
{
	Matrix3 rotateMat;
	SetRotation(a_rad, rotateMat);

	localMatrix = rotateMat * localMatrix;
}

void Transform::SetRotation(float a_rad, Matrix3& a_rotateMatrix)
{
	a_rotateMatrix.m00 = cos(a_rad);
	a_rotateMatrix.m10 = -sin(a_rad);
	a_rotateMatrix.m01 = sin(a_rad);
	a_rotateMatrix.m11 = cos(a_rad);
}

void Transform::SetParent(Transform * a_parent)
{
	m_parent = a_parent;
	m_parent->AddChild(*this);
}

Matrix3 Transform::GetLocalMatrix()
{
	return localMatrix;
}

Matrix3 Transform::GetGlobalMatrix()
{
	return globalMatrix;
}

void Transform::UpdateTransforms()
{
	if (m_parent != nullptr)
		globalMatrix = localMatrix * m_parent->GetGlobalMatrix();
	else
		globalMatrix = localMatrix;

	// Update Children
	for (int i = 0; i < m_children.size(); i++)
	{
		m_children[i]->UpdateTransforms();
	}
}

Vector2 Transform::GetPosition()
{
	return localMatrix.GetPos();
}

void Transform::AddChild(Transform & a_child)
{
	m_children.push_back(&a_child);
}
