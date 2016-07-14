#pragma once
#include <string>
#include <vector>
#include "BaseEntity.h"
#include "Player.h"
#include "Transform.h"
#include "glfw3.h"
#include "SpriteBatch.h"
class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void Update(float deltaTime);
	void Draw(SpriteBatch* a_spriteBatch);

	void AddEntity(int a_entType);

	Transform       rootTransform;

private:
	std::vector<BaseEntity*> m_entities;
	int idCount;
};

