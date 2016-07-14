#pragma once
#include "GraphNode.h"

class GraphNode;
class GraphEdge
{
public:
	GraphEdge(GraphNode& a_start, GraphNode& a_end, float a_cost);
	~GraphEdge();

	GraphNode* m_start;
	GraphNode* m_end;
	float m_cost;

};

