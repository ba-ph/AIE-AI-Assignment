#include "Graph.h"

Graph::Graph()
{
}


Graph::~Graph()
{
	std::list<GraphNode*>::iterator iterator = m_nodes.begin();
	for (; iterator != m_nodes.end(); iterator++)
	{
		delete *iterator;
	}
	m_nodes.clear();
}

void Graph::RemoveEdge(GraphNode & a_start, GraphNode & a_end)
{
	std::list<GraphNode*>::iterator iterator = m_nodes.begin();
	for (; iterator != m_nodes.end(); iterator++)
	{
		//		if ((*iterator)->m_edges) )
		//		{
		//
		//}
		//	}
	}
}

GraphNode * Graph::GetNode(int a_node)
{
	std::list<GraphNode*>::iterator iter = m_nodes.begin(a_node);
	return m_nodes.
}

void Graph::RemoveNode(GraphNode& a_node)
{
	std::list<GraphNode*>::iterator iterator = m_nodes.begin();
	for (; iterator != m_nodes.end(); iterator++)
	{
		if (*iterator == &a_node)
		{
			delete *iterator;
			m_nodes.erase(iterator);
			break;
		}
	}
}

GraphNode* Graph::AddNode(const Vector2 & a_data)
{
	GraphNode* newNode = new GraphNode(a_data);

	m_nodes.push_back(newNode);
	return newNode;
}

GraphEdge* Graph::AddEdge(GraphNode & a_start, GraphNode & a_end, float a_cost)
{
	a_start.AddEdge(a_end, a_cost);
	return nullptr;
}



void Graph::Draw(SpriteBatch & a_spritebatch)
{
	std::list<GraphNode*>::iterator iter = m_nodes.begin();

	for (; iter != m_nodes.end(); iter++)
	{
		Vector2 nodePos = (*iter)->data;

		DrawCircle(a_spritebatch, nodePos, 20.0f);

		std::list<GraphEdge*>::iterator edgeIter = (*iter)->m_edges.begin();
		for (; edgeIter != (*iter)->m_edges.end(); edgeIter++)
		{
			Vector2 v1 = (*edgeIter)->m_start->data;
			Vector2 v2 = (*edgeIter)->m_end->data;

			a_spritebatch.drawLine(v1.x, v1.y, v2.x, v2.y, 2.0f);
		}
	}
}

void Graph::DrawCircle(SpriteBatch & a_spritebatch, Vector2 pos, float radius)
{
	Vector2 oldPos = Vector2(pos.x + (cos(0.0f) * radius), pos.y + (sin(0.0f) * radius));

	for (float i = 0; i < 2 * 3.1457f; i += 3.1457f / 10.0f)
	{
		Vector2 newPos;

		newPos.x = pos.x + (cos(i) * radius);
		newPos.y = pos.y + (sin(i) * radius);

		a_spritebatch.drawLine(oldPos.x, oldPos.y, newPos.x, newPos.y, 2.0f);

		oldPos = newPos;
	}
}

std::list<GraphNode*> Graph::FindPathBetween(GraphNode * start, GraphNode * end)
{
	std::list<GraphNode*>::iterator nodeIter = m_nodes.begin();

	for (; nodeIter != m_nodes.end(); nodeIter++)
	{
		(*nodeIter)->gScore = std::numeric_limits<float>::max();
		(*nodeIter)->previous = nullptr;
		(*nodeIter)->Traversed = false;
		(*nodeIter)->order = 0;
	}

	std::list<GraphNode*> PriorityQueue;


	PriorityQueue.push_back(start);
	start->IsOnStack = true;
	start->previous = start;
	start->gScore = 0;

	while (!PriorityQueue.empty())
	{
		PriorityQueue.sort(CompareGScore(start, end));

		GraphNode* currnode = *PriorityQueue.begin();

		if (currnode == end)
			break;

		PriorityQueue.remove(currnode);
		currnode->Traversed = true;

		std::list<GraphEdge*>::iterator edgeIter = currnode->m_edges.begin();

		for (; edgeIter != currnode->m_edges.end(); edgeIter++)
		{
			if ((*edgeIter)->m_end->Traversed == false)
			{
				float gScore = currnode->gScore + (*edgeIter)->m_cost;

				if (gScore < (*edgeIter)->m_end->gScore)
				{
					(*edgeIter)->m_end->gScore = gScore;
					(*edgeIter)->m_end->previous = currnode;
				}
				if ((*edgeIter)->m_end->IsOnStack == false)
				{
					PriorityQueue.push_back((*edgeIter)->m_end);
					(*edgeIter)->m_end->IsOnStack = true;
				}
			}
		}

		std::list<Vector2> path;

		while (currnode->previous != start)
		{
			path.push_front(currnode->data);

			currnode = currnode->previous;
		}

		path.push_front(start->data);
	}

}
