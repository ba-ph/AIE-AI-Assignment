#pragma once
#include "Vector2.h"
#include "DecisionNode.h"

class Agent;
class FleeAction : public DecisionNode
{
public:
	FleeAction();
	~FleeAction();

	void Execute(Agent* a_agent);

private:
	 
};

