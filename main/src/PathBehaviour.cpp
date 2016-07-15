#include "PathBehaviour.h"



PathBehaviour::PathBehaviour()
{
}


PathBehaviour::~PathBehaviour()
{
}

void PathBehaviour::Update(Agent * a_agent)
{

	//check to see if agent is within threshold to current target node


	//calculate force vector        //replace this with path
	Vector2 vecBetweenAgentTarget = *m_targetPos - a_agent->GetPosition();
	Vector2 force = vecBetweenAgentTarget.Normalized() * a_agent->m_maxVelocity;

	//Add the force
	a_agent->AddForce(force - a_agent->m_velocity);
}

void PathBehaviour::Draw(float deltaTime)
{



	
}


