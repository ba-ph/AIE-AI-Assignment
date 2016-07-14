#include "Polygon.h"





Polygon::Polygon()
{
	m_transform = new Transform();
}

Polygon::Polygon(Transform & a_transform)
{
	m_transform = &a_transform;
}

Polygon::~Polygon()
{
}

void Polygon::addVertex(const Vector2 & a_vec)
{
	m_verticies.push_back(a_vec);
	
}

void Polygon::Draw(SpriteBatch * a_sprBatch)
{
	Vector2 p1;
	Vector2 p2;

	for (int i = 0; i < m_verticies.size() - 1; i++)
	{
		p1 = m_transform->TransformedPoint(m_verticies[i]);
		p2 = m_transform->TransformedPoint(m_verticies[i+1]);
		a_sprBatch->drawLine(p1.x, p1.y, p2.x, p2.y);
	}

	p1 = m_transform->TransformedPoint(m_verticies[m_verticies.size() - 1]);
	p2 = m_transform->TransformedPoint(m_verticies[0]);

	a_sprBatch->drawLine(p1.x, p1.y, p2.x, p2.y);
}

Vector2 Polygon::Min()
{
	Vector2 min;

	min.x = m_verticies[0].x;
	min.y = m_verticies[0].y;
	
	for (int i = 0; i < m_verticies.size(); i++) {
		if (m_verticies[i].x < min.x) {

			min.x = m_verticies[i].x;
		}

		if (m_verticies[i].y < min.y) {

			min.y = m_verticies[i].y;
		}
	}
	return min;
}

Vector2 Polygon::Max()
{
	Vector2 max;
	max.x = m_verticies[0].x;
	max.y = m_verticies[0].y;

	for (int i = 0; i < m_verticies.size(); i++) {
		if (m_verticies[i].x > max.x) {

			max.x = m_verticies[i].x;
		}

		if (m_verticies[i].y > max.y) {

			max.y = m_verticies[i].y;
		}
	}
	return max;
}

Polygon Polygon::TransformedPolygon()
{
	Polygon transformedPolygon(*m_transform);
	transformedPolygon = *this;
	if (m_verticies.size() > 0) {
		for (int i = 0; i < transformedPolygon.m_verticies.size(); i++) {
			transformedPolygon.m_verticies[i] = m_transform->GetGlobalMatrix() * m_verticies[i];
		}
	}
	return transformedPolygon;
}



