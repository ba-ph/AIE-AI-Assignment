#include "DecisionNode.h"

#include "Agent.h"

DecisionNode::DecisionNode()
{

}

DecisionNode::~DecisionNode()
{

}

void DecisionNode::AddChild(DecisionNode * a_newNode)
{
	m_children.push_back(a_newNode);
}
