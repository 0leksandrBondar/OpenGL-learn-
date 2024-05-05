#pragma once

#include "glad.h"
#include "GLFW/glfw3.h"

#include "../Singleton/ISingleton.h"

class MainWindow : public ISingleton<MainWindow>
{
public:
	explicit MainWindow(GLFWwindow* window = nullptr);
	~MainWindow() = default;

	GLFWwindow* GetWindow();

	void initWindow();

private:

	static void glfwWindowSizeCallback(GLFWwindow* window, int width, int height);
	static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

private:
	GLFWwindow* _mainWindow;
};

