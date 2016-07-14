#include "EntityManager.h"


EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{

}

void EntityManager::Update(float deltaTime)
{

	//Call the update for each ent
	for (int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->Update(deltaTime);
	}
}

void EntityManager::Draw(SpriteBatch* a_spriteBatch)
{
	rootTransform.UpdateTransforms();

	//Call the draw for each ent
	for (int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->Draw(a_spriteBatch);
	}
}

void EntityManager::AddEntity(int a_entType)
{
	//Add a new entity
	if (a_entType == 1)
	{
		m_entities.push_back(new Player(315.5f, new Texture("./bin/textures/player.png"), rootTransform));
		m_entities[0]->m_transform->Translate(Vector2(45, 350));
	}

	if (a_entType == 2)
	{
		m_entities.push_back(new Player2(315.5f, new Texture("./bin/textures/player.png"), rootTransform));
		m_entities[1]->m_transform->Translate(Vector2(1235, 350));
	}

	if (a_entType == 3)
	{
		m_entities.push_back(new Ball(new Texture("./bin/textures/ball.png"), rootTransform));
		m_entities[2]->m_transform->Translate(Vector2(640, 360));
		m_entities[2]->m_maxVel
	}
}
