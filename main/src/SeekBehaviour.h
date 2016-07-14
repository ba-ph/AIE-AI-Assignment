#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include "Agent.h"

class SeekBehaviour : public IBehaviour
{
public:
	SeekBehaviour();
	~SeekBehaviour();

	Vector2* m_targetPos;

	virtual void Update(Agent* a_agent);
};

