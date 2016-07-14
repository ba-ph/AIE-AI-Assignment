#pragma once

class Agent;
class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	virtual void Update(Agent* a_agent) = 0;
};
