#include "MainWindow.h"

#include <iostream>

MainWindow::MainWindow(GLFWwindow* window) : _mainWindow {window}
{
}

void MainWindow::initWindow()
{
	if (GLFWwindow* window = glfwCreateWindow(1000, 800, "OpenGL", nullptr, nullptr))
	{
		glfwSetWindowSizeCallback(window, glfwWindowSizeCallback);
		glfwSetKeyCallback(window, glfwKeyCallback);
		glfwMakeContextCurrent(window);
		_mainWindow = window;
	}
	else
	{
		std::cerr << "creation window failed!";
	}
}

GLFWwindow* MainWindow::GetWindow()
{
	return _mainWindow;
}

void MainWindow::glfwWindowSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void MainWindow::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}