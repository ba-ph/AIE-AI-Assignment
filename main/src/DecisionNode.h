#pragma once
#include <vector>


class Agent;
class DecisionNode
{

public:
	DecisionNode();
	~DecisionNode();

	void AddChild(DecisionNode* a_newNode);
	virtual void Execute(Agent* a_agent) = 0;


private:
	std::vector<DecisionNode*> m_children;
};