#include "WanderAction.h"

#include "Agent.h"

#define PI 3.14159265359f

WanderAction::WanderAction()
{
}

WanderAction::~WanderAction()
{
}

void WanderAction::Execute(Agent * a_agent)
{
	std::cout << "WANDER" << std::endl;

	Vector2 randomTargetOnCircle;

	if (/*a_agent->WanderTargetCalculated == false*/ true)
	{
		float randomDeg = rand() % 360;
		float randomRadian = randomDeg * PI / 180.0f;

		randomTargetOnCircle = Vector2(cos(randomRadian), sin(randomRadian));
		randomTargetOnCircle = randomTargetOnCircle * wanderRadius;
	}
	else
	{
		//randomTargetOnCircle = a_agent->prevWanderTarget;
	}

	//Jitter Vector
	float randomDeg = rand() % 360;
	float randomRadian = randomDeg * PI / 180.0f;


	Vector2 jitterVector(cos(randomRadian), sin(randomRadian));
	jitterVector = jitterVector * jitterAmount;

	// Add jitter vector to target vector
	randomTargetOnCircle += jitterVector;
	// Bring target back to circle
	randomTargetOnCircle = randomTargetOnCircle.Normalized() * wanderDistance;

	//Add agent heading * wanderdist
	randomTargetOnCircle;


	//a_agent->prevWanderTarget = randomTargetOnCircle;

	randomTargetOnCircle += a_agent->GetPosition();

	//calculate seek force
	Vector2 vecBetween = randomTargetOnCircle - a_agent->GetPosition();
	Vector2 force = vecBetween.Normalized() * a_agent->m_maxVelocity;

	//Add force to agent
	a_agent->AddForce(force - a_agent->m_velocity);
}
