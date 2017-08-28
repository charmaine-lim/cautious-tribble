
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: utils.h
// Description	: utils declaration file.
// Authors		: Charmaine Lim
// Mail			: Charmaine.Lim6440@mediadesign.school.nz

#pragma once

#include "glew/glew.h"
#include "freeglut/freeglut.h"
#include "soil/SOIL.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <strstream>
#include <string>

class Model;

enum EModelType
{
	CUBE, TRIANGLE, SPHERE, CIRCLE, PYRAMID, QUAD
};

//Position Structure defines a single point for a primitive shape
struct Position {
	Position() {}
	Position(GLfloat x, GLfloat y, GLfloat z)
		: _fX(x), _fY(y), _fZ(z) {

	}

	GLfloat _fX;
	GLfloat _fY;
	GLfloat _fZ;
};

//Normalise texture coordinates
struct TexCoord
{
	GLfloat _fX;
	GLfloat _fY;
};

//Normalised Color values RGB
struct Color
{
	Color() {}
	Color(GLfloat x, GLfloat y, GLfloat z)
		: _fX(x), _fY(y), _fZ(z) {
	}
	GLfloat _fX;
	GLfloat _fY;
	GLfloat _fZ;
};

//Defines 3 points in the vertices array that will define a primitive
//, _fX, _fY, _fZ define Points 1, 2, 3 respectively.
struct IndexFormat
{
	IndexFormat() {}
	IndexFormat(GLfloat x, GLfloat y, GLfloat z) : _fX(x), _fY(y), _fZ(z)
	{
	}

	GLfloat _fX;
	GLfloat _fY;
	GLfloat _fZ;
};

//Structure contatining the 3 attributes used in defining a fragment. 
//The a single vertex(Point on the primitive)
//The texture normal attribute
//The color normal attribute
struct VertexFormat
{
	VertexFormat() {}
	VertexFormat(GLfloat x, GLfloat y, GLfloat z, GLfloat TexX, GLfloat TexY, GLfloat nX, GLfloat nY, GLfloat nZ)
	{
		VertexPosition._fX = x;
		VertexPosition._fY = y;
		VertexPosition._fZ = z;
		TexturePosition._fX = TexX;
		TexturePosition._fY = TexY;
		Color._fX = nX;
		Color._fY = nY;
		Color._fZ = nZ;
	}

	Position VertexPosition;
	TexCoord TexturePosition;
	Color  Color;

};


class Utils
{
	Utils() {}
	~Utils() {}

public:

	static void SetCube(Model& _rModel);
	static void SetQuad(Model& _rModel);
	static void SetTriangle(Model& _rModel);
	static void SetPyramid(Model& _rModel);
	static void SetCircle(Model& _rModel);
	static void SetSphere(Model& _rModel);
	static float WIDTH;
	static float HEIGHT;
	static bool g_Play;
};

#define VALIDATE(a) if (!a) return (false)

template<typename T>
std::string ToString(const T& _value)
{
	std::strstream theStream;
	theStream << _value << std::ends;
	return (theStream.str());
}