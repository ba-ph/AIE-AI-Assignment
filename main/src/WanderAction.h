#pragma once
#include <iostream>
#include "DecisionNode.h"


class Agent;

class WanderAction : public DecisionNode
{
public:
	WanderAction();
	~WanderAction();

	void Execute(Agent* a_agent);

private:
	float wanderRadius;
	float wanderDistance;
	float jitterAmount;
};

