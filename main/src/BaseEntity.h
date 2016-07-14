#pragma once
#include "Vector2.h"
#include "Texture.h"
#include "Transform.h"
#include "SpriteBatch.h"
#include "InputManager.h"
#include "Polygon.h"
#include "AABBCollider.h"

class BaseEntity
{
public:
	BaseEntity();
	~BaseEntity();

	virtual void Update(float deltaTime);
	void Draw(SpriteBatch* a_spriteBatch);

	void AddForce(Vector2& a_velocity);
	void SetPolygon(Polygon& a_polygon);
	void SetPosition(Vector2& a_position);
	Vector2 GetPosition();
	Transform& GetTransform();
	Polygon& GetPolygon();
	
	//Entities position vector (used by transform mat)
	Vector2 m_position;
	//Velocity
	Vector2 m_velocity;
	//Force this frame
	Vector2 m_force;
	//Direction
	Vector2 m_heading;
	//Max velocity of entity
	float m_maxVelocity;

protected:
	//AABBCollider m_collider;
	Polygon m_polygon;
	Transform m_transform;
	Texture* m_texture;	
};

