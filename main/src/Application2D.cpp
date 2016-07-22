#include "Application2D.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Transform.h"
#include "Vector2.h"
#include "BaseEntity.h"
#include "EntityManager.h"
#include <ctime>
#include <random>
#include "Graph.h"
#include "GraphNode.h"
#include "DecisionNode.h"
#include "WanderAction.h"
#include "FleeAction.h"
#include "PathAction.h"
#include "SeekAction.h"
#include "CheckDistanceDecision.h"



Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	srand(time(NULL));
	createWindow("A.I.E Project", 1280, 920);
	setBackgroundColour(0.7f, 0.7f, 0.7f);
	m_spriteBatch = new SpriteBatch();

	//GetInput().SetWindowInstance(m_window);
	getCursorPositionVec(m_mousePos);

	//Create a hexagon
	Polygon hexagon(agent.GetTransform());
	hexagon.addVertex(Vector2(-50, 30));
	hexagon.addVertex(Vector2(0, 50));
	hexagon.addVertex(Vector2(50, 30));
	hexagon.addVertex(Vector2(50, -30));
	hexagon.addVertex(Vector2(0, -50));
	hexagon.addVertex(Vector2(-50, -30));

	//Set up agent 
	agent.SetPolygon(hexagon);
	agent.GetTransform().SetParent(rootTransform);
	agent.GetTransform().Scale(0.5f);
	agent.SetPosition(Vector2(200.0f, 200.0f));
	agent.m_maxVelocity = 400.0f;

	//TEMP SET UP OF DECISION TREE
	PathAction* pathActoin = new PathAction();
	SeekAction* seekAction = new SeekAction();
	FleeAction* fleeAction = new FleeAction();
	WanderAction* wanderAction = new WanderAction();
	CheckDistanceDecision* checkDistanceDicision = new CheckDistanceDecision();
	checkDistanceDicision->SetActions(pathActoin, fleeAction);
	checkDistanceDicision->SetDistanceThreshold(35000.0f);

	agent.SetTarget(m_mousePos);
	agent.SetRootNode(checkDistanceDicision);

	///////////////


	// Create a graph
	pGraph = new Graph();
	// Fill Graph
	CreateGraph();


	//bad timers because I'm too lazy to make a waskeyreleased function
	timer = 0.0f;
	cooldown = 0.1f;
	StartMouseNode = nullptr;
	TargetMouseNode = nullptr;
	clickCount = 0;
	///////////////


	//Setting up InputManager
	Input::CreateSingleton();
	m_input = Input::GetSingleton();
	//Need to update singleton function to take in Vector2
	m_mouseX = 0;
	m_mouseY = 0;


	return true;
}

void Application2D::shutdown() {

	delete m_spriteBatch;
	delete pGraph;

	Input::DestroySingleton();

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	timer += deltaTime;
	getCursorPositionVec(m_mousePos);

	agent.Update(deltaTime);
	agent.UpdateTarget(m_mousePos);


	//m_input->GetMouseXY(&m_mouseX, &m_mouseY);
	
	rootTransform.UpdateTransforms();

	//Remove Nodes
	if (m_input->WasKeyPressed(GLFW_KEY_Y))
		pGraph->RemoveNode(*pGraph->GetClosestNode(m_mousePos));

	//Toggle Graph Draw
	if (m_input->WasKeyPressed(GLFW_KEY_G) && timer >= cooldown)
	{
		if (pGraph->GraphEnabled)
			pGraph->GraphEnabled = false;
		else
			pGraph->GraphEnabled = true;
		timer = 0.0f;
	}

	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	//Calculate path                                
	if (pGraph->m_nodes.size() > 2)
	{
		//Calculate path
		path = pGraph->AStar(pGraph->GetNode(0), pGraph->GetNode(0) /*pGraph->GetNode(pGraph->m_nodes.size() -1)*/);

		//Draw the path
		auto currPos = path.begin();
		for (; currPos != path.end(); currPos++)
		{
			//Set nextPos to currPos + 1
			auto nextPos = currPos;
			nextPos++;

			//Check nextPos isn't end of our path
			if (nextPos == path.end())
				break;

			Vector2 p1 = (*currPos);
			Vector2 p2 = (*nextPos);
			m_spriteBatch->setSpriteColor(1, 0.0f, 0.0f, 5.0f);
			m_spriteBatch->drawLine(p1.x, p1.y, p2.x, p2.y, 2.0f);
		}
	}

	agent.Draw(m_spriteBatch);

	if (pGraph->GraphEnabled) {
		pGraph->Draw(*m_spriteBatch);
	}

	// done drawing sprites
	m_spriteBatch->end();
}

void Application2D::CreateGraph()
{
	const int cols = 18;
	const int rows = 13;

	GraphNode* grid[cols][rows];

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			Vector2 gridPos(i*75.0f, j*75.0f);
			grid[i][j] = pGraph->AddNode(gridPos);
		}
	}

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (j < rows - 1) {
				pGraph->AddEdge(*grid[i][j], *grid[i][j + 1], 10);
				pGraph->AddEdge(*grid[i][j + 1], *grid[i][j], 10);
			}
			if (i < cols - 1) {
				pGraph->AddEdge(*grid[i][j], *grid[i + 1][j], 10);
				pGraph->AddEdge(*grid[i + 1][j], *grid[i][j], 10);
			}

			if (i < cols - 1 && j < rows - 1) {
				pGraph->AddEdge(*grid[i][j], *grid[i + 1][j + 1], 10);
				pGraph->AddEdge(*grid[i + 1][j + 1], *grid[i][j], 10);
			}

			if (i < cols - 1 && j < rows - 1) {
				pGraph->AddEdge(*grid[i + 1][j], *grid[i][j + 1], 10);
				pGraph->AddEdge(*grid[i][j + 1], *grid[i + 1][j], 10);
			}
		}
	}
}

