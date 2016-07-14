#include "Ball.h"



Ball::Ball()
{
}

Ball::Ball(Texture* a_texture, Transform& a_rootTransform)
{
	m_speed = 350.0f;
	m_texture = a_texture;
	m_transform = new Transform();
	m_transform->SetParent(&a_rootTransform);
}


Ball::~Ball()
{
}


void Ball::Update(float deltaTime) 
{
	AddForce(Vector2(300, 0));
	BaseEntity::Update(deltaTime);

}
void Ball::Draw(SpriteBatch* a_spriteBatch)
{
	a_spriteBatch->drawSpriteTransformed3x3(m_texture, m_transform->GetGlobalMatrix());
}