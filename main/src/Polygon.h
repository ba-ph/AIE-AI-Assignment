#pragma once
#include <vector>
#include "src\Transform.h"
#include "Vector2.h"
#include "src\SpriteBatch.h"
class Polygon
{
public:
	Polygon(Transform& a_transform);
	~Polygon();

	void addVertex(const Vector2& a_vec);
	void Draw(SpriteBatch* a_spriteBatch);
	Vector2 Min();
	Vector2 Max();
	Polygon TransformPolygon();
	


private:
	std::vector<Vector2> m_verticies;
	Transform* m_transform;
};

