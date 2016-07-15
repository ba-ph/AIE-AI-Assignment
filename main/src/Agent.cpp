#include "Agent.h"
#include "BaseEntity.h"



Agent::Agent()
{
}


Agent::~Agent()
{
}


void Agent::Update(float deltaTime)
{
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
