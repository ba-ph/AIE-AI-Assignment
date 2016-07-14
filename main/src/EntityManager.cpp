#include "EntityManager.h"


EntityManager::EntityManager()
{
	idCount = 0;
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
		//m_entities.push_back(new Player(215.5f, new Texture("./bin/textures/crate.png"), rootTransform, idCount++, "Player"));
	}
}
