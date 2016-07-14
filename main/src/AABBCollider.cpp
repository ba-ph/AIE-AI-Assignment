#include "AABBCollider.h"
#include "Polygon.h"
#include "src\SpriteBatch.h"


AABBCollider::AABBCollider()
{
}

AABBCollider::AABBCollider(AABBCollider & rhs)
{


}

AABBCollider::AABBCollider(float a_minX, float a_maxX, float a_minY, float a_maxY)
{

}


AABBCollider::~AABBCollider()
{
}

void AABBCollider::SetPolyGon(Polygon & a_polygon)
{
	m_polygon = &a_polygon;
	m_min = a_polygon.Min();
	m_max = a_polygon.Max();
}

void AABBCollider::Draw(SpriteBatch * a_spriteBatch)
{
	a_spriteBatch->drawLine(m_min.x, m_min.y, m_max.x, m_max.y, 1);
	a_spriteBatch->drawLine(m_max.x, m_min.y, m_max.x, m_max.y, 1);
	a_spriteBatch->drawLine(m_max.x, m_max.y, m_min.x, m_max.y, 1);
	a_spriteBatch->drawLine(m_min.x, m_max.y, m_min.x, m_min.y, 1);
}

void AABBCollider::Update()
{
	Polygon m_transformedPolygon = m_polygon->TransformPolygon();
	m_min = m_transformedPolygon.Min();
	m_max = m_transformedPolygon.Max();
}
