#include "BaseEntity.h"


BaseEntity::BaseEntity()
{

}

BaseEntity::~BaseEntity()
{

}

void BaseEntity::Update(float deltaTime)
{
	//collision not working
	//m_collider.Update();
	//m_transform.SetTranslationLocalMat(m_position);
	m_position.x = m_transform.GetLocalMatrix().m02;
	m_position.y = m_transform.GetLocalMatrix().m12;

	//Calculate velocity based on force applied
	m_velocity += m_force * deltaTime;

	//Clamp velocity based on maxVelocity
	if (m_velocity.Magnitude() > m_maxVelocity)
	{
		m_velocity = m_velocity.Normalized()*m_maxVelocity;
	}

	//Add velocity to position
	m_position += m_velocity * deltaTime;

	//Clear forces
	m_force = Vector2();
	m_transform.SetTranslationLocalMat(m_position);
}

void BaseEntity::Draw(SpriteBatch * a_spriteBatch)
{
	//m_collider.Draw(a_spriteBatch);
	m_polygon.Draw(a_spriteBatch);
}

void BaseEntity::AddForce(Vector2 & a_force)
{
	m_force += a_force;
}

void BaseEntity::SetPolygon(Polygon & a_polygon)
{
	m_polygon = a_polygon;
	//m_collider.SetPolyGon(a_polygon);
}

void BaseEntity::SetPosition(Vector2 & a_position)
{
	m_position = a_position;
	m_transform.SetTranslationLocalMat(a_position);
}

Vector2 BaseEntity::GetPosition()
{
	return m_position;
}

Transform & BaseEntity::GetTransform()
{
	return m_transform;
}

Polygon & BaseEntity::GetPolygon()
{
	return m_polygon;
}

