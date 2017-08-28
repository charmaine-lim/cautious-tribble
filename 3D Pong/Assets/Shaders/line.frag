
#version 430 core

out vec4 color;

uniform vec3 lineColour;

void main()
{    

	color = vec4(lineColour, 1.0); 
}