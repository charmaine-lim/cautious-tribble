//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: ShaderLoader.h
// Description	: Shader Loader declaration file.
// Authors		: Charmaine Lim 
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once

#include "glew/glew.h"
#include "freeglut/freeglut.h"

#include <iostream>

class ShaderLoader
{
private:

	std::string ReadShader(char *filename);
	GLuint CreateShader(GLenum shaderType,
		std::string source,
		char* shaderName);

public:

	ShaderLoader(void);
	~ShaderLoader(void);
	GLuint CreateProgram(char* VertexShaderFilename,
		char* FragmentShaderFilename);
};
