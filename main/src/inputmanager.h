#pragma once
#include <GLFW\glfw3.h>
class Input
{
public:
	friend Input& GetInput();
	void SetWindowInstance(GLFWwindow* a_window);
	bool isKeyPressed(int key);
	bool isMouseButtonPressed(int button);
	void getCursorPosition(int& x, int& y);
	~Input();

private:
	Input();
	GLFWwindow* m_window;
};

Input& GetInput();