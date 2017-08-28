//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Quadrilateral.h
// Description	: Quadrilateral declaration file.
// Authors		: Charmaine Lim
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once

#include <vector>;

#include "glm/glm.hpp"
#include "Camera.h"

class Line;

//This class draws a rectagle or square using the line class
//This is used to draw the background of green squares
//This class is also extended to be used as the player's paddle and the opponent's paddle
//This is done by adding a cross inside the quad.
//Ideally though the paddle should be replaced by a paddle image which is slightly transparent, use alpha blending
class Quadrilateral
{
public:
	Quadrilateral();
	~Quadrilateral();

	void CreateQuad(glm::vec3 leftTopCorner, int iWidth, int iHeight);
	void Render(Camera& _camera);

	void setPosition(glm::vec3 _position);
	void setIsPaddle(bool _bIsPaddle);
	void setColor(glm::vec3 _color);

private:

	std::vector<Line*> m_vecLines;

	bool m_bIsPaddle;
};
