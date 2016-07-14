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




Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	srand(time(NULL));
	createWindow("A.I.E Project", 1280, 720);
	m_spriteBatch = new SpriteBatch();

	GetInput().SetWindowInstance(m_window);
	getCursorPositionVec(m_mousePos);

	//Create a hexagon
	Polygon hexagon(object1.GetTransform());
	hexagon.addVertex(Vector2(-50, 30));
	hexagon.addVertex(Vector2(0, 50));
	hexagon.addVertex(Vector2(50, 30));
	hexagon.addVertex(Vector2(50, -30));
	hexagon.addVertex(Vector2(0, -50));
	hexagon.addVertex(Vector2(-50, -30));

	//set up object1
	object1.SetPolygon(hexagon);
	object1.GetTransform().SetParent(rootTransform);
	object1.GetTransform().Scale(0.5f);
	object1.SetPosition(Vector2(200.0f, 200.0f));
	object1.m_maxVelocity = 600.0f;	

	//setup behaviours

	//Seek
	seekBehaviour.m_targetPos = &m_mousePos;

	//Wander
	wanderBehaviour.wanderDistance = 100.0f;
	wanderBehaviour.wanderRadius = 100.0f;
	wanderBehaviour.jitterAmount = 20.0f;

	
	//assign them
	object1.AddBehaviour(&seekBehaviour);

	// Create a graph
	pGraph = new Graph();
	// Fill Graph
	CreateGraph();

	//std::list<Vector2> Path = pGraph->FindPathBetween(pGraph->m_nodes.begin(), pGraph->m_nodes.end())


	return true;
}

void Application2D::shutdown() {

	delete m_spriteBatch;
	delete pGraph;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {

	getCursorPositionVec(m_mousePos);

	//if (isMouseButtonPressed(0))
	//{
	//	getCursorPositionVec(m_mousePos);
	//	//m_mapNodes.push_back(pGraph->AddNode(m_mousePos));
	//}
	//if (isMouseButtonPressed(1))
	//{
	//	//getCursorPositionVec(m_mousePos);
	//	//iterate through all nodes and check distance
	//	int i = 0;
	//	while (i < pGraph->m_nodes.size())
	//	{
	//		if (m_mousePos.Distance(pGraph->m_nodes[]  ->data) < 20.0f)
	//		{
	//			//Call remove node from Graph
	//			pGraph->RemoveNode(*m_mapNodes[i]);
	//			m_mapNodes.erase(m_mapNodes.begin() + i);
	//			break;
	//		}
	//		i++;
	//	}	
	//

	//Time::UpdateDeltaTime(deltaTime);
	rootTransform.UpdateTransforms();

	//object1.Update(deltaTime);

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
	std::list<Vector2> path = pGraph->FindPathBetween(pGraph->m_nodes.begin(), pGraph->m_nodes.end());

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
		m_spriteBatch->drawLine(p1.x, p1.y, p2.x, p2.y, 0.5f);


	}

	//m_spriteBatch->drawSprite(m_bgTexture, 0, 0);

	pGraph->Draw(*m_spriteBatch);
	//object1.Draw(m_spriteBatch);

	// done drawing sprites
	m_spriteBatch->end();	
}

void Application2D::CreateGraph()
{
	const int graphSize = 20;
	GraphNode* grid[graphSize][graphSize];

	for (int i = 0; i <graphSize; i++)
	{
		for (int j = 0; j < graphSize; j++)
		{
			Vector2 gridPos(i*75.0f, j*75.0f);
			grid[i][j] = pGraph->AddNode(gridPos);

		}

	}

	for (int i = 0; i <graphSize; i++)
	{
		for (int j = 0; j < graphSize; j++)
		{
			if (j < graphSize -1) {
				pGraph->AddEdge(*grid[i][j], *grid[i][j + 1], 10);
				pGraph->AddEdge(*grid[i][j + 1], *grid[i][j], 10);
			}
			if (i < graphSize - 1) {

				pGraph->AddEdge(*grid[i][j], *grid[i + 1][j], 10);
				pGraph->AddEdge(*grid[i + 1][j], *grid[i][j], 10);
			}

		}

	}



}