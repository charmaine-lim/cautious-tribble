#version 430 core

layout(location = 0) in vec4 vertex;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

void main()
{
	//gl_Position = projection * view * model * vertex;
	gl_Position =  projection * view  * model  * vertex;
}