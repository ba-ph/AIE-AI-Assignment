#pragma once
#include "DecisionNode.h"

class Vector2;
class Agent;
class SeekAction : public DecisionNode
{
public:
	SeekAction();
	~SeekAction();

	void Execute(Agent* a_agent);

private:

};

