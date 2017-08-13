//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Model.h
// Description	: Encapsulate required functionality and components to define and render a predefined shape.
// Authors		: Charmaine Lim 
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once

//Local Includes
#include "Utils.h"
#include "Camera.h"

//Library Includes
#include <vector>


class Model
{

public:
	Model();
	Model(EModelType Shape, char* Filename);
	~Model();

	//GLuint program;

	GLuint vao;
	GLuint vbo;
	GLuint ebo;
	GLuint texture;
	GLuint texture2;

	EModelType Shape;

	//Containers for model vertices and indices, allowing the model class to to define any shape constructible through primitives
	std::vector<VertexFormat>	vertices;
	std::vector<GLuint>			indices;

	//Unused IndexFormat, due to the additional allocation and the clunky code produced.
	//Easier understood however, each vertex clearly defined.
	//std::vector<IndexFormat>	indices;

	//Scale, Position and Rotation Components
	glm::quat m_Rotation;
	glm::vec3 m_Position;
	glm::vec3 m_Scale;

	//Stored by the constructor for use in the initialiser.
	char* texturePath;

	//Render the model using an externaly provided camera for projection and view matrix, and an externally supplied program.
	void Render(GLuint program, Camera& camera);
	void Initialise();


	//void Render(Camera& camera);
	//void Initialise(vec3 _vPosition = 0, vec3 _vScale = 1, vec3 _qRot = 0);

	void SetPosition(glm::vec3 _position);
	glm::vec3 getPosition();
	glm::vec3 getScale();

public:

};
