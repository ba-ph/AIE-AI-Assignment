#include "Player.h"

Player::Player()
{
	/*m_speed = 0;
	m_transform = new Transform();
	m_transform->SetParent(nullptr);
	m_texture = nullptr;*/
}

Player::Player(float a_speed, Texture* a_texture, Transform& a_rootTrans, int a_objectID, std::string a_objectName)
{
	/*m_speed = a_speed;
	m_texture = a_texture;
	m_transform = new Transform();
	m_transform->SetParent(&a_rootTrans);
	m_objectName = a_objectName;
	m_objectID = a_objectID;*/
}

Player::~Player()
{
	//delete m_transform;
	//delete m_texture;
}

void Player::Update(float deltaTime)
{
	/*if (GetInput().isKeyPressed(GLFW_KEY_W))
		m_transform->Translate(Vector2(0, m_speed * deltaTime));
	if (GetInput().isKeyPressed(GLFW_KEY_A))
		m_transform->Translate(Vector2(-m_speed * deltaTime, 0));
	if (GetInput().isKeyPressed(GLFW_KEY_S))
		m_transform->Translate(Vector2(0, -m_speed * deltaTime));
	if (GetInput().isKeyPressed(GLFW_KEY_D))
		m_transform->Translate(Vector2(m_speed * deltaTime, 0));
	if (GetInput().isKeyPressed(GLFW_KEY_Q))
		m_transform->Rotate(-1 * deltaTime);
	if (GetInput().isKeyPressed(GLFW_KEY_E))
		m_transform->Rotate(1 * deltaTime);
	if (GetInput().isKeyPressed(GLFW_KEY_F))
		m_transform->Scale(0.99);
	if (GetInput().isKeyPressed(GLFW_KEY_G))
		m_transform->Scale(1.01);*/
}

void Player::Draw(SpriteBatch* a_spriteBatch)
{
	//a_spriteBatch->drawSpriteTransformed3x3(m_texture, m_transform->GetGlobalMatrix());
}