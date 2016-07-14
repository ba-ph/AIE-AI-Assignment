/////////////////////////////////
// AUTHOR:        James Creaton
// LAST MODIFIED: 02/06/2016  
/////////////////////////////////
#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include <vector>
class Transform
{
public:
	Transform();
	~Transform();

	//Extras
	void SetScale(float a_scale, Matrix3& a_scaleMat);
	void Scale(float a_scale);
	void Translate(const Vector2& a_translation);
	void SetTranslation(const Vector2& a_translation, Matrix3& a_translateMatrix);
	void SetTranslationLocal(const Vector2& a_translation);
	void Rotate(float a_rad);
	void SetRotation(float a_rad, Matrix3& a_rotateMatrix);


	void SetParent(Transform* a_parent);

	
	Matrix3 GetLocalMatrix();
	Matrix3 GetGlobalMatrix();

	void UpdateTransforms();

	Vector2 GetPosition();


private:
	Matrix3 localMatrix;
	Matrix3 globalMatrix;


	void AddChild(Transform& a_child);

	//Parent Pointer
	Transform* m_parent;
	//Store Children
	std::vector<Transform*> m_children;
};

