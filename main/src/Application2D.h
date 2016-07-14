#pragma once

#include "BaseApplication.h"
#include "Transform.h"
#include "Player.h"

class Vector2;
class SpriteBatch;
class Texture;
class Font;
class EntityManager;

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

};