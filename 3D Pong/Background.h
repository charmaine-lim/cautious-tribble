#pragma once

#include <vector>;

#include "glm\glm.hpp"

class Camera;
class Quadrilateral;
class Line;

// This class creates the green square background made of lines
// It is used by the Menu Scene and the Game Scene
class Background
{
public:
	Background();
	~Background();

	void CreateQuads();
	void CreateLines();
	void Render(Camera& camera);

private:
	std::vector<Quadrilateral*> m_vecQuads;
	std::vector<Line*> m_vecLines;

	glm::vec3 m_topLeftCorner;
	int m_iWidth;
	int m_iHeight;
	float m_zDistance;
};


