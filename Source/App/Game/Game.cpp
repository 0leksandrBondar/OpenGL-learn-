#include "Game.h"

#include "../Windows/MainWindow.h"
#include "../Managers/ShaderManager.h"

void Game::startGameLoop()
{
	while (!glfwWindowShouldClose(MainWindow::GetInstance()->GetWindow()))
	{
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(ShaderManager::GetInstance()->getShaderProgramId());
		glBindVertexArray(ShaderManager::GetInstance()->getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(MainWindow::GetInstance()->GetWindow());
		glfwPollEvents();
	}
}

Game::~Game()
{
	glfwTerminate();
}
