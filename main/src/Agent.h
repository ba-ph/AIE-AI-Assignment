#pragma once
#include <vector>
#include "IBehaviour.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"
#include "PathBehaviour.h"

#include "BaseEntity.h"
#include <list>

class Agent : public BaseEntity
{
public:
	Agent();
	~Agent();

	void Update(float deltaTime);
	void AddBehaviour(IBehaviour* a_behaviour);

	SeekBehaviour seekBehaviour;
	WanderBehaviour wanderBehaviour;
	PathBehaviour pathBehaviour;

	std::vector<IBehaviour*> m_behaviours;
	
	std::list<Vector2> path;

};

