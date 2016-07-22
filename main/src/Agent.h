#pragma once
#include <vector>
#include "IBehaviour.h"
#include "BaseEntity.h"
#include <list>

class DecisionNode;

class Agent : public BaseEntity
{
public:
	Agent();
	~Agent();

	void Update(float deltaTime);
	void AddBehaviour(IBehaviour* a_behaviour);

	void SetRootNode(DecisionNode* a_rootNode);


	void UpdateTarget(Vector2 a_newTargetPos);
	Vector2 GetTarget();
	void SetTarget(Vector2 a_newTargetPos);


	std::vector<IBehaviour*> m_behaviours;
	std::list<Vector2> path;

private:
	DecisionNode* rootNode;
	Vector2 m_targetPos;
	std::vector<Vector2> path;

	float m_timer;

};

