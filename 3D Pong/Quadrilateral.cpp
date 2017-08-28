
#include "Quadrilateral.h"
#include "Line.h"

Quadrilateral::Quadrilateral()
{
	m_bIsPaddle = false;
}

Quadrilateral::~Quadrilateral()
{
	//clean up the vector of pointers
	while (m_vecLines.size() > 0)
	{
		Line* pLine = m_vecLines[m_vecLines.size() - 1];
		m_vecLines.pop_back();
		delete pLine;
	}
}

// this function creates either a square or a rectangle 
// given the point on the left top corner of the quad
// and the width and height of the quad
// the plane that this quad will be drawn is XY plane
// we will be moving this quad in the z axis later.
void Quadrilateral::CreateQuad(glm::vec3 leftTopCorner, int iWidth, int iHeight)
{
	//these 4 points are the 4 corners of the Quad
	glm::vec3 topLeft(leftTopCorner.x, leftTopCorner.y, leftTopCorner.z);
	glm::vec3 topRight(leftTopCorner.x + iWidth, leftTopCorner.y, leftTopCorner.z);
	glm::vec3 bottomLeft(leftTopCorner.x, leftTopCorner.y - iHeight, leftTopCorner.z);
	glm::vec3 bottomRight(leftTopCorner.x + iWidth, leftTopCorner.y - iHeight, leftTopCorner.z);

	//create the 4 lines from the 4 corners of the quad
	m_vecLines.push_back(new Line(topLeft, topRight));
	m_vecLines.push_back(new Line(topLeft, bottomLeft));
	m_vecLines.push_back(new Line(topRight, bottomRight));
	m_vecLines.push_back(new Line(bottomLeft, bottomRight));

	//if this quad is a panel, add a cross inside
	if (m_bIsPaddle)
	{
		//midpoints of the quad's 4 lines
		glm::vec3 middleLeft(leftTopCorner.x, leftTopCorner.y - iHeight / 2.0f, leftTopCorner.z);
		glm::vec3 middleRight(topRight.x, topRight.y - iHeight / 2.0f, topRight.z);
		glm::vec3 middleTop(leftTopCorner.x + iWidth / 2.0f, leftTopCorner.y, leftTopCorner.z);
		glm::vec3 middleBottom(bottomLeft.x + iWidth / 2.0f, bottomLeft.y, bottomLeft.z);

		//the horizontal and vertical lines of the cross (forming a target)
		Line* middleHorizontal = new Line(middleLeft, middleRight);
		Line* midddleVertical = new Line(middleTop, middleBottom);

		m_vecLines.push_back(middleHorizontal);
		m_vecLines.push_back(midddleVertical);
	}
}

void Quadrilateral::Render(Camera& _camera)
{
	for (int i = 0; i < m_vecLines.size(); i++)
	{
		m_vecLines[i]->Render(_camera);
	}
}

void Quadrilateral::setIsPaddle(bool _bIsPaddle)
{
	m_bIsPaddle = _bIsPaddle;
}

void Quadrilateral::setPosition(glm::vec3 _position)
{
	for (int i = 0; i < m_vecLines.size(); i++)
	{
		m_vecLines[i]->setPosition(_position);
	}
}

//this color needs to be set after creating the quad
void Quadrilateral::setColor(glm::vec3 _color)
{
	for (int i = 0; i < m_vecLines.size(); i++)
	{
		m_vecLines[i]->setColor(_color);
	}
}