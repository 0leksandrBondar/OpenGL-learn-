#pragma once

#include "glad.h"
#include "GLFW/glfw3.h"

#include "../Singleton/ISingleton.h"

#include <string>

class ShaderManager : public ISingleton<ShaderManager>
{
public:
	ShaderManager() = default;

	void initVAO();

	void initVBO(GLfloat* vertices, size_t size);
	[[nodiscard]] const GLuint getVAO() const;

	[[nodiscard]] const GLuint getShaderProgramId() const;
	void createShaderProgram();

	void initShaderParams(int index, int size);
	void initFragShader(const char * pathToShader);

	void initVertexShader(const char * pathToShader);

private:

	[[nodiscard]] const char* getShader(const std::string& pathToShader) const;

	void deleteShaders();

private:
	GLuint VAO = 0;
	GLuint VBO = 0;

	GLuint _fragShader = 0;
	GLuint _vertexShader = 0;
	GLuint _shaderProgramId = 0;
};