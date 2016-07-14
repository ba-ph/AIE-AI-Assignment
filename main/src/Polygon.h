#pragma once
#include "Vector2.h"
#include "SpriteBatch.h"
#include "Transform.h"
#include <vector>


class Polygon
{
public:
	Polygon();
	Polygon(Transform& a_transform);
	~Polygon();


	void addVertex(const Vector2& a_vec);
	void Draw(SpriteBatch* a_sprBatch);


	Vector2 Min();
	Vector2 Max();


	Polygon TransformedPolygon();
	Transform* m_transform;
private:
	std::vector<Vector2> m_verticies;
};

