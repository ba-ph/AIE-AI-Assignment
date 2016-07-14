#pragma once

#include "Vector2.h"
#include <list>
#include "GraphEdge.h"

class GraphEdge;
class GraphNode
{
public:
	GraphNode(const Vector2& a_data);
	~GraphNode();

	//Required
	void AddEdge(GraphNode& a_end, float a_cost);

	//Optional
	void RemoveEdge(GraphNode& a_end);

	//extra
//	void AddEdge(GraphEdge* a_edge);
//	void RemoveEdge(GraphEdge a_edge);

	
	std::list<GraphEdge*> m_edges;

	float gScore;
	GraphNode* previous;

	bool Traversed;
	bool IsOnStack;
	int order;
	Vector2 data;

};

bool CompareGScore(const GraphNode* a, const GraphNode* b);

