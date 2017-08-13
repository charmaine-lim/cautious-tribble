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

//#include "glew/glew.h"
//#include "freeglut/freeglut.h"
//#include "soil/SOIL.h"

//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"

#include "ShaderLoader.h"
#include "Camera.h"
#include "Utils.h"

//#include "ft2build.h"
//#include FT_FREETYPE_H  

//#include <map>
//#include <string>
//#include <iostream>



class Line
{
public:
	Line(glm::vec3 _startPos, glm::vec3 _endPos);
	~Line();

	void Render(Camera& camera);
	//void setPosition(glm::vec3 _position);
	void setColor(glm::vec3 _color);
	//void setHighlight(glm::vec3 _color) { highlight = _color; };
	//void setScale(GLfloat _scale);

	//void setText(std::string _text);
	//void AddText(unsigned char c);

//	void setActive(bool b) { m_bIsActive = b; };
	//void setButton(bool b) { m_bIsButton = b; };
	//void setHighlighted(bool b) { m_bIsHighlighted = b; };

	//bool isActive() { return m_bIsActive; };
	//bool isButton() { return m_bIsButton; };
	//bool isHighlighted() { return m_bIsHighlighted; };

	//std::string getText() { return text; };
	glm::vec3 position;

	//int width, height;

//	bool m_bIsButton = true;
//	bool m_bIsActive = true;
//	bool m_bIsHighlighted = false;


private:
	//std::string text;
	//GLfloat scale;
	glm::vec3 color;
	//glm::vec3 highlight;

	GLuint VAO, VBO, program;
	//std::map<GLchar, Character> Characters;

	//For the sake of this smaller game, an unchanging shader can be static.
	//static GLuing program;
	glm::vec3 m_startPos;
	glm::vec3 m_endPos;
};

