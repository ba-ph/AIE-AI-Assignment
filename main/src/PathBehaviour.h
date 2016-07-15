#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include "Agent.h"

class PathBehaviour : public IBehaviour
{
public:
	PathBehaviour();
	~PathBehaviour();

	Vector2* m_targetPos;

	virtual void Update(Agent* a_agent);
	virtual void Draw(float deltaTime);

};

