#include "SeekBehaviour.h"

SeekBehaviour::SeekBehaviour()
{

}

SeekBehaviour::~SeekBehaviour()
{

}

void SeekBehaviour::Update(Agent * a_agent)
{
	//calculate force vector
	Vector2 vecBetweenAgentTarget = *m_targetPos - a_agent->GetPosition();
	Vector2 force = vecBetweenAgentTarget.Normalized() * a_agent->m_maxVelocity;

	//Add the force
	a_agent->AddForce(force - a_agent->m_velocity);
}
