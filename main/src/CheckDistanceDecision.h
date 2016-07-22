#pragma once
#include "DecisionNode.h"

class PathAction;
class SeekAction;
class FleeAction;
class Agent;
class CheckDistanceDecision : public DecisionNode
{
public:
	CheckDistanceDecision();
	~CheckDistanceDecision();

	void SetDistanceThreshold(float a_threshold);
	void SetActions(PathAction* a_pathAction, FleeAction* a_fleeAction);

	void Execute(Agent* a_agent);



private:
	FleeAction* m_trueDecision;
	PathAction* m_falseDecision;
	float m_distanceThreshold;


};

