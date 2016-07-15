#pragma once
#include <vector>
#include "IBehaviour.h"
#include "BaseEntity.h"
#include <list>

class Agent : public BaseEntity
{
public:
	Agent();
	~Agent();

	void Update(float deltaTime);
	void AddBehaviour(IBehaviour* a_behaviour);

	std::vector<IBehaviour*> m_behaviours;
	
	std::list<Vector2> path;

};

