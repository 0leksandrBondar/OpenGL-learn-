#include "Game/Game.h"
#include "Managers/ShaderManager.h"
#include "Windows/MainWindow.h"

#include "glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

void initGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void initGLAD()
{
	if (!gladLoadGL())
	{
		std::cout << "can't load GLAD!";
	}
}

int main()
{
	initGLFW();
	MainWindow::GetInstance()->initWindow();
	initGLAD();

	GLfloat vertices[] = {1.0f, -0.5f, -1.0f, -0.5f, 0.0f, 1.0f};
	GLfloat colorVertices[] = {1.0f, -0.5f, -1.0f, -0.5f, 0.0f, 1.0f};

	ShaderManager::GetInstance()->initVertexShader("assets/shaders/main.vert");
	ShaderManager::GetInstance()->initFragShader("assets/shaders/main.frag");
	ShaderManager::GetInstance()->createShaderProgram();

	ShaderManager::GetInstance()->initVBO(vertices, sizeof(vertices));
	ShaderManager::GetInstance()->initVAO();

	ShaderManager::GetInstance()->initShaderParams(0,2);

	Game::GetInstance()->startGameLoop();

	return 0;
}
