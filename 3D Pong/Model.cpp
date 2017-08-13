//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Model.cpp
// Description	: Encapsulate required functionality and components to define and render a predefined shape.
// Authors		: Charmaine Lim 
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#include "Model.h"
#include "Camera.h"

Model::Model()
{

}

Model::~Model()
{

}

Model::Model(EModelType Shape, char* Filename)
{
	switch (Shape)
	{
	case QUAD:
		Utils::SetQuad(*this);
		break;

	case CUBE:
		Utils::SetCube(*this);
		break;

	case TRIANGLE:
		Utils::SetTriangle(*this);
		break;

	case PYRAMID:
		Utils::SetPyramid(*this);
		break;

	case CIRCLE:
		Utils::SetCircle(*this);
		break;
	case SPHERE:
		Utils::SetSphere(*this);
		break;
	}

	m_Scale = glm::vec3(1, 1, 1);
	texturePath = Filename;
}

void Model::Initialise()
{
	//Create the singular array of vertices and their attribues
	GLfloat buffer[200];
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		buffer[0 + (8 * i)] = vertices[i].VertexPosition._fX;
		buffer[1 + (8 * i)] = vertices[i].VertexPosition._fY;
		buffer[2 + (8 * i)] = vertices[i].VertexPosition._fZ;

		buffer[3 + (8 * i)] = vertices[i].TexturePosition._fX;
		buffer[4 + (8 * i)] = vertices[i].TexturePosition._fY;

		buffer[5 + (8 * i)] = vertices[i].Color._fX;
		buffer[6 + (8 * i)] = vertices[i].Color._fY;
		buffer[7 + (8 * i)] = vertices[i].Color._fZ;
	}

	//Create the singular array of vertex indices
	GLuint bufferIndices[200];
	for (unsigned int i = 0; i < indices.size(); i++)
	{
		bufferIndices[i] = indices[i];
	}


	//Buffer Creation
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), buffer, GL_STATIC_DRAW);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(bufferIndices), bufferIndices, GL_STATIC_DRAW);

	//Attribute Setting
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);


	//Texture Position
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	//Vertex Normals
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set texutre wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image(texturePath, &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}


void Model::Render(GLuint program, Camera& camera)
{
	glUseProgram(program);

	GLfloat currentTime = (GLfloat)glutGet(GLUT_ELAPSED_TIME);
	currentTime = currentTime / 1000;//convert millisecond to seconds

									 //get uniform location from program and set currentTime value
	GLint currentTimeLocation = glGetUniformLocation(program, "currentTime");
	glUniform1f(currentTimeLocation, currentTime);

	GLint modelLoc = glGetUniformLocation(program, "model");
	GLint viewLoc = glGetUniformLocation(program, "view");
	GLint projLoc = glGetUniformLocation(program, "projection");

	glm::mat4 model;
	//Translate the model according to its position and apply the rotation
	model = glm::translate(model, m_Position) * glm::mat4(m_Rotation);
	//Scale the model according to private member m_Scale
	model = glm::scale(model, m_Scale);

	//Send the values to the uniform variables in the program supplied in the function call
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.GetViewMatrix()));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera.GetProjectionMatrix()));

	//Bind the texture to the uniform variable 
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(program, "Texture"), 0);

	//Bind, draw and unbind the vertex array 
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Model::SetPosition(glm::vec3 _position)
{
	m_Position = _position;
}

glm::vec3 Model::getPosition()
{
	return m_Position;
}

glm::vec3 Model::getScale()
{
	return m_Scale;
}