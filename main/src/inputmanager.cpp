#include "InputManager.h"

Input::Input()
{

}

void Input::SetWindowInstance(GLFWwindow* a_window) {
	m_window = a_window;

}
bool Input::isKeyPressed(int key)
{

	return glfwGetKey(m_window, key) == GLFW_PRESS;
}
bool Input::isMouseButtonPressed(int button)
{
	return glfwGetMouseButton(m_window, button) == GLFW_PRESS;
}
void Input::getCursorPosition(int& x, int& y) {
	double dx = 0, dy = 0;
	glfwGetCursorPos(m_window, &dx, &dy);
	x = (int)dx; y = (int)dy;
}
Input::~Input()
{
}

Input& GetInput()
{
	static Input instance;
	return instance;

}
