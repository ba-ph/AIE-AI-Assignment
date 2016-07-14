#pragma once
#include "Vector2.h"
class SpriteBatch;
class Polygon;
class AABBCollider
{
public:
	AABBCollider();
	AABBCollider(AABBCollider& rhs);
	AABBCollider(float a_minX, float a_maxX, float a_minY, float a_maxY);
	~AABBCollider();

	void SetPolyGon(Polygon& a_polygon);
	void Draw(SpriteBatch* a_spriteBatch);
	void Update();

	Vector2 m_min;
	Vector2 m_max;

private:
	Polygon* m_polygon;
	
};

