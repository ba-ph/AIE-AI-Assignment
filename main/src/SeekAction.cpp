#include "SeekAction.h"
#include "Agent.h"
#include "Vector2.h"


SeekAction::SeekAction()
{
}


SeekAction::~SeekAction()
{
}

void SeekAction::Execute(Agent * a_agent)
{
	//calculate force vector
	Vector2 vecBetweenAgentTarget = a_agent->GetTarget() - a_agent->GetPosition();
	Vector2 force = vecBetweenAgentTarget.Normalized() * a_agent->m_maxVelocity;

	//Add the force
	a_agent->AddForce(force - a_agent->m_velocity);
}
