#include "CheckDistanceDecision.h"
#include "Agent.h"
#include "SeekAction.h"
#include "FleeAction.h"
#include "PathAction.h"



CheckDistanceDecision::CheckDistanceDecision()
{

}


CheckDistanceDecision::~CheckDistanceDecision()
{
}

void CheckDistanceDecision::SetDistanceThreshold(float a_threshold)
{
	m_distanceThreshold = a_threshold;
}

void CheckDistanceDecision::SetActions(PathAction* a_pathAction, FleeAction * a_fleeAction)
{
	m_trueDecision = a_fleeAction;
	m_falseDecision = a_pathAction;
}

void CheckDistanceDecision::Execute(Agent* a_agent)
{
	if ((a_agent->GetPosition() - a_agent->GetTarget()).SqaureMagnitude() < m_distanceThreshold)
		m_trueDecision->Execute(a_agent);
	else
		m_falseDecision->Execute(a_agent);
}
