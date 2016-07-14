#include "GraphNode.h"

GraphNode::GraphNode(const Vector2 & a_data)
{
	data = a_data;
}

GraphNode::~GraphNode()
{
	std::list<GraphEdge*>::iterator iter = m_edges.begin();

	for (; iter != m_edges.end(); iter++)
	{
		
	}
}

void GraphNode::AddEdge(GraphNode & a_end, float a_cost)
{
	m_edges.push_back(new GraphEdge(*this, a_end, a_cost));
}

void GraphNode::RemoveEdge(GraphNode & a_end)
{
	std::list<GraphEdge*>::iterator iter = m_edges.begin();

	for (; iter != m_edges.end(); iter++)
	{
		if ((*iter)->m_end == &a_end)
		{
			delete *iter;
			m_edges.remove(*iter);
			return;
		}
	}
}

bool CompareGScore(const GraphNode * a, const GraphNode * b)
{
	return a->gScore < b->gScore;
}
