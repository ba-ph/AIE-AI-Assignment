#pragma once
#include "BaseApplication.h"


class Vector2;
class SpriteBatch;
class Texture;
class Font;
class EntityManager;
class BaseEntity;
class Graph;
class GraphNode;

#include "Agent.h"
#include "PathBehaviour.h"
#include "IBehaviour.h"
#include <vector>
#include "Polygon.h"
#include "inputmanager.h"

class Application2D : public BaseApplication {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

protected:

	SpriteBatch*	m_spriteBatch;
	Texture*		m_bgTexture;
	Font*			m_font;

private:
	EntityManager* m_entityManager;
	Input* m_input;

	Graph* pGraph;
	void CreateGraph();

	Vector2 m_mousePos;
	Transform rootTransform;
	Agent agent;


	PathBehaviour pathBehaviour;
	GraphNode* StartMouseNode;
	GraphNode* TargetMouseNode;

	std::list<Vector2> path;

	
	//bad
	int m_mouseX;
	int m_mouseY;
	float timer;
	float cooldown;
	int clickCount;
};