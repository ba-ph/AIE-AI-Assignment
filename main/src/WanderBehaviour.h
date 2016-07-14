#pragma once
#include "IBehaviour.h"
#include "Agent.h"

class WanderBehaviour : public IBehaviour
{
public:
	WanderBehaviour();
	~WanderBehaviour();

	float wanderRadius;
	float wanderDistance;
	float jitterAmount;

	Vector2 prevWanderTarget;


	void Update(Agent* a_agent);

};

