#pragma once
#include "DecisionNode.h"
#include "Agent.h"

class PathAction : public DecisionNode
{
public:
	PathAction();
	~PathAction();

	void Execute(Agent* a_agent);

private:

};

