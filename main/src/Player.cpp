#include "Player.h"

Player::Player()
{
	m_speed = 0;
	m_transform = new Transform();
	m_transform->SetParent(nullptr);
	m_texture = nullptr;
}

Player::Player(float a_speed, Texture* a_texture, Transform& a_rootTrans)
{
	m_speed = a_speed;
	m_texture = a_texture;
	m_transform = new Transform();
	m_transform->SetParent(&a_rootTrans);
}

Player::~Player()
{
	delete m_transform;
	delete m_texture;
}

void Player::Update(float deltaTime)
{
	if (GetInput().isKeyPressed(GLFW_KEY_W))
		m_transform->Translate(Vector2(0, m_speed * deltaTime));
	if (GetInput().isKeyPressed(GLFW_KEY_S))
		m_transform->Translate(Vector2(0, -m_speed * deltaTime));
}

void Player::Draw(SpriteBatch* a_spriteBatch)
{
	a_spriteBatch->drawSpriteTransformed3x3(m_texture, m_transform->GetGlobalMatrix());
}