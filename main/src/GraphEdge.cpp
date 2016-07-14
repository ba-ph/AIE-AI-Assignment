#include "GraphEdge.h"


GraphEdge::GraphEdge(GraphNode & a_start, GraphNode & a_end, float a_cost)
{
	m_start = &a_start;
	m_end = &a_end;
	m_cost = a_cost;
}

GraphEdge::~GraphEdge()
{

}
