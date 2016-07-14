#pragma once
#include "Vector2.h"
#include "Texture.h"
#include "Transform.h"
#include "SpriteBatch.h"
#include "InputManager.h"
class BaseEntity
{
public:
	BaseEntity();
	BaseEntity(float a_speed, Texture* a_texture, Transform& a_rootTrans);
	~BaseEntity();

	virtual void Update(float deltaTime);
	virtual void Draw(SpriteBatch* a_spriteBatch) = 0;
	
	void AddForce(Vector2 a_velocity);


	Vector2 m_velocity;
	Vector2 m_force;
	Vector2 m_heading;
	Vector2 m_position;


	float m_speed;
	Transform* m_transform;
	Texture* m_texture;
	std::string m_objectName;
	int m_objectID;
};

