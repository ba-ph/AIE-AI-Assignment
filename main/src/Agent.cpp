#include "Agent.h"
#include "BaseEntity.h"

#include "DecisionNode.h"



Agent::Agent()
{
}


Agent::~Agent()
{
}


void Agent::Update(float deltaTime)
{
	m_timer += deltaTime;
	rootNode->Execute(this);

	//SENSE

	//THINK

	//ACT
	std::vector<IBehaviour*>::iterator iter = m_behaviours.begin();

	for (; iter != m_behaviours.end(); iter++)
	{
		(*iter)->Update(this);
	}

	BaseEntity::Update(deltaTime);

}

void Agent::AddBehaviour(IBehaviour * a_behaviour)
{
	m_behaviours.push_back(a_behaviour);
}

void Agent::SetRootNode(DecisionNode* a_rootNode)
{
	rootNode = a_rootNode;
}

void Agent::UpdateTarget(Vector2 a_newTargetPos)
{
	m_targetPos = a_newTargetPos;
}

Vector2 Agent::GetTarget()
{
	return m_targetPos;
}

void Agent::SetTarget(Vector2 a_newTargetPos)
{
	m_targetPos = a_newTargetPos;
}
