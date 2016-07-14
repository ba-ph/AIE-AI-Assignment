#include "Player2.h"

Player2::Player2()
{
}

Player2::Player2(float a_speed, Texture* a_texture, Transform& a_rootTrans)
{
	m_speed = a_speed;
	m_texture = a_texture;
	m_transform = new Transform();
	m_transform->SetParent(&a_rootTrans);
}

Player2::~Player2()
{
	delete m_texture;
	delete m_transform;
}


void Player2::Update(float deltaTime)
{
	if (GetInput().isKeyPressed(GLFW_KEY_UP))
		m_transform->Translate(Vector2(0, m_speed * deltaTime));
	if (GetInput().isKeyPressed(GLFW_KEY_DOWN))
		m_transform->Translate(Vector2(0, -m_speed * deltaTime));
}

void Player2::Draw(SpriteBatch * a_spriteBatch)
{
	a_spriteBatch->drawSpriteTransformed3x3(m_texture, m_transform->GetGlobalMatrix());
}
