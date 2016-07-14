#include "BaseEntity.h"


BaseEntity::BaseEntity()
{

}

BaseEntity::BaseEntity(float a_speed, Texture* a_texture, Transform& a_rootTrans)
{
	
}


BaseEntity::~BaseEntity()
{

}

void BaseEntity::Update(float deltaTime)
{
	m_position = m_transform->GetPosition();

	m_velocity += m_force * deltaTime;

	if (m_velocity.Magnitude() > 1500.0f)
		m_velocity = m_velocity.Normalized() * 1500.0f;


	m_position += m_velocity * deltaTime;

	m_heading = m_velocity.Normalized();

	// clear forces
	m_force = Vector2();
	m_transform->SetTranslationLocal(m_position);
}

void BaseEntity::AddForce(Vector2 a_velocity)
{
	m_force += a_velocity;
}
