//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Line.h
// Description	: Line declaration file.
// Authors		: Charmaine Lim
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once

#include "glm/glm.hpp"

#include "ShaderLoader.h"
#include "Camera.h"
#include "Utils.h"

//This class draws a line from a starting position to an ending position
class Line
{
public:
	Line() {};
	Line(glm::vec3 _startPos, glm::vec3 _endPos);
	~Line();

	void Render(Camera& camera);

	void setColor(glm::vec3 _color);
	void setPosition(glm::vec3 _position);

	glm::vec3 position;


private:

	glm::vec3 color;

	GLuint VAO, VBO, program;

	glm::vec3 m_startPos;
	glm::vec3 m_endPos;

	glm::vec3 m_position;
};

