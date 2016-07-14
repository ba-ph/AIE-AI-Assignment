#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Vector2.h"
#include "EntityManager.h"


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I.E Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();
	m_bgTexture = new Texture("./bin/textures/bg.png");

	// Create a new EntityManager
	m_entityManager = new EntityManager();

	m_entityManager->AddEntity(1);
	m_entityManager->AddEntity(2);
	m_entityManager->AddEntity(3);
	

	GetInput().SetWindowInstance(m_window);

	return true;
}

void Application2D::shutdown() {

	delete m_spriteBatch;
	delete m_bgTexture;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {

	m_entityManager->Update(deltaTime);

	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	
	m_entityManager->Draw(m_spriteBatch);
	m_spriteBatch->drawSprite(m_bgTexture, 640.0f, 360.0f);

	

	// done drawing sprites
	m_spriteBatch->end();	
}