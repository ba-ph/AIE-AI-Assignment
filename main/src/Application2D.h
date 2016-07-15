#pragma once
#include "BaseApplication.h"


class Vector2;
class SpriteBatch;
class Texture;
class Font;
class EntityManager;
class Socket;
class BaseEntity;
class Graph;
class GraphNode;

#include "Agent.h"
#include "WanderBehaviour.h"
#include "SeekBehaviour.h"
#include "IBehaviour.h"
#include <vector>

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

	void CreateGraph();

	Vector2 m_mousePos;
	EntityManager* m_entityManager;
	Graph* pGraph;

	Transform rootTransform;

};