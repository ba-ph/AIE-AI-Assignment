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

#include <Windows.h>




Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	srand(time(NULL));
	createWindow("A.I.E Project", 1280, 910);
	m_spriteBatch = new SpriteBatch();

	GetInput().SetWindowInstance(m_window);
	getCursorPositionVec(m_mousePos);

	// Create a graph
	pGraph = new Graph();
	// Fill Graph
	CreateGraph();

	return true;
}

void Application2D::shutdown() {

	delete m_spriteBatch;
	delete pGraph;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {

	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	getCursorPositionVec(m_mousePos);

	//Time::UpdateDeltaTime(deltaTime);
	rootTransform.UpdateTransforms();

	if (isMouseButtonPressed(1))
	{
		GraphNode* temp = pGraph->GetClosestNode(m_mousePos);

		pGraph->RemoveNode(*temp);
	}
	//object1.Update(deltaTime);

	if (isKeyPressed(GLFW_KEY_G))
	{
		if (pGraph->GraphEnabled)
		{
			pGraph->GraphEnabled == false;
		}
		pGraph->GraphEnabled == true;
	}

	

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	//Calculate path                                 
	//std::list<Vector2> path = pGraph->Dijkstra(pGraph->GetNode(14), pGraph->GetNode(64));
	if (pGraph->m_nodes.size() > 2)
	{
		std::list<Vector2> path = pGraph->AStar(pGraph->GetNode(0), pGraph->GetNode(pGraph->m_nodes.size() -1));

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
	

	m_spriteBatch->setSpriteColor(1, 1, 1, 1);

	//m_spriteBatch->drawSprite(m_bgTexture, 0, 0);

	pGraph->Draw(*m_spriteBatch);
	//object1.Draw(m_spriteBatch);

	// done drawing sprites
	m_spriteBatch->end();	
}

void Application2D::CreateGraph()
{
	const int cols = 13;
	const int rows = 13;
	//const int graphSize = 30;

	GraphNode* grid[cols][rows];

	for (int i = 0; i <cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			Vector2 gridPos(i*75.0f, j*75.0f);
			grid[i][j] = pGraph->AddNode(gridPos);
		}
	}

	for (int i = 0; i <cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (j < cols -1) {
				pGraph->AddEdge(*grid[i][j], *grid[i][j + 1], 10);
				pGraph->AddEdge(*grid[i][j + 1], *grid[i][j], 10);
			}
			if (i < rows - 1) {

				pGraph->AddEdge(*grid[i][j], *grid[i + 1][j], 10);
				pGraph->AddEdge(*grid[i + 1][j], *grid[i][j], 10);
			}

			if (i < rows -1 && j < cols -1)
			{
				pGraph->AddEdge(*grid[i][j], *grid[i + 1][j + 1], 10);
				pGraph->AddEdge(*grid[i + 1][j + 1], *grid[i][j], 10);
			}

			if (i < rows -1 && j < cols -1)
			{
				pGraph->AddEdge(*grid[i + 1][j], *grid[i][j + 1], 10);
				pGraph->AddEdge(*grid[i][j + 1], *grid[i + 1][j], 10);
			}
		}
	}
}