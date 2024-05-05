#include "ShaderManager.h"

#include <fstream>
#include <iostream>

void ShaderManager::initVertexShader(const char * pathToShader)
{
	const char* vertexShaderProgram = getShader(pathToShader);
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderProgram, nullptr);
	glCompileShader(vertexShader);
	_vertexShader = vertexShader;
}

void ShaderManager::initFragShader(const char * pathToShader)
{
	const char* fragShaderProgram = getShader(pathToShader);
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fragShaderProgram, nullptr);
	glCompileShader(fragShader);
	_fragShader = fragShader;
}

void ShaderManager::createShaderProgram()
{
	GLuint shaderProgramId = glCreateProgram();
	glAttachShader(shaderProgramId, _vertexShader);
	glAttachShader(shaderProgramId, _fragShader);
	glLinkProgram(shaderProgramId);
	if (shaderProgramId != 0)
	{
		_shaderProgramId = shaderProgramId;
	}
	else
	{
		std::cerr << "can not create a shader program";
	}

	deleteShaders();
}

void ShaderManager::deleteShaders()
{
	glDeleteShader(_vertexShader);
	glDeleteShader(_fragShader);
}

void ShaderManager::initVBO(GLfloat* vertices, size_t size)
{
	GLuint vbo = 0;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	VBO = vbo;
}

void ShaderManager::initVAO()
{
	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	VAO = vao;
}

void ShaderManager::initShaderParams(int index, int size)
{
	glEnableVertexAttribArray(index);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, 0, nullptr);
}

const GLuint ShaderManager::getShaderProgramId() const
{
	return _shaderProgramId;
}

const GLuint ShaderManager::getVAO() const
{
	return VAO;
}

const char* ShaderManager::getShader(const std::string& pathToShader) const
{
	std::ifstream frag("assets/shaders/main.frag");
	std::string shaderProgram((std::istreambuf_iterator<char>(frag)),
		std::istreambuf_iterator<char>());
	return shaderProgram.data();
}
