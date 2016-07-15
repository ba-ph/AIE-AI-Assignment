#pragma once
#include "GraphEdge.h"
#include "GraphNode.h"
#include "Vector2.h"
#include "SpriteBatch.h"
#include <list>

class Graph
{
public:
	Graph();
	~Graph();

	//Required
	GraphNode* AddNode(const Vector2& a_data);
	GraphEdge* AddEdge(GraphNode& a_start, GraphNode& a_end, float a_cost);



	//Optional
	void AddNode(GraphNode& a_node);
	void RemoveEdge(GraphNode& a_start, GraphNode& a_end);
	GraphNode* GetNode(int a_node);

	//Node to be removed deconstructor cleans up edges
	void RemoveNode(GraphNode& a_node);
	void RemoveNode(const Vector2& a_data);

	void Draw(SpriteBatch& a_spritebatch);
	void DrawCircle(SpriteBatch& a_spritebatch, Vector2 pos, float radius);


	GraphNode* GetClosestNode(const Vector2 a_data);

	std::list<Vector2> Dijkstra(GraphNode* start, GraphNode* end);
	std::list<Vector2> AStar(GraphNode* start, GraphNode* end);

	bool DistanceHeuristic(GraphNode* start, GraphNode* end);

	bool GraphEnabled;

	std::list<GraphNode*> m_nodes;
};

