//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Line.cpp
// Description	: Line implementation file.
// Authors		: Charmaine Lim 
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#include "Line.h"


Line::Line(glm::vec3 _startPos, glm::vec3 _endPos)
{
	m_position = glm::vec3(0, 0, 0);

	//default color is green
	color = glm::vec3(0.0, 1.0, 0.0);

	//starting point and ending point of the line
	m_startPos = _startPos;
	m_endPos = _endPos;

	ShaderLoader shaderLoader;
	program = shaderLoader.CreateProgram("Assets/Shaders/line.vert", "Assets/Shaders/line.frag");

	GLfloat vertices[] = { m_startPos.x, m_startPos.y, m_startPos.z, 1.0f,
		m_endPos.x, m_endPos.y, m_endPos.z, 1.0f };


	// Configure VAO/VBO for texture quads
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

Line::~Line()
{
}

void Line::Render(Camera& camera)
{

	glm::vec3 textPos = this->position;

	//enable blending
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Activate corresponding render state	
	glUseProgram(program);
	//glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(Utils::WIDTH), 0.0f, static_cast<GLfloat>(Utils::HEIGHT));
	glm::mat4 projection = glm::perspective(45.0f, static_cast<GLfloat>(Utils::WIDTH)/ static_cast<GLfloat>(Utils::HEIGHT), 0.1f, 100.0f);

	//glm::mat4 model = glm::translate(model, position);
	glm::mat4 model;
	model = glm::translate(model, m_position);
	//glm::mat4 view;
	//glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(camera.GetProjectionMatrix()));
	glUniformMatrix4fv(glGetUniformLocation(program, "view"), 1, GL_FALSE, glm::value_ptr(camera.GetViewMatrix()));
	glUniformMatrix4fv(glGetUniformLocation(program, "model"), 1, GL_FALSE, glm::value_ptr(model));

	glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	glUniform3f(glGetUniformLocation(program, "lineColour"), color.x, color.y, color.z);
	
	glBindVertexArray(VAO);

	// Update content of VBO memory
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	// Be sure to use glBufferSubData and not glBufferData

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// Render quad
	glDrawArrays(GL_LINES, 0, 6);


	glBindVertexArray(0);
	//glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_CULL_FACE);
	glDisable(GL_BLEND);

}

void Line::setColor(glm::vec3 _color) 
{
	color = _color;
}

void Line::setPosition(glm::vec3 _position)
{
	m_position = _position;
}
