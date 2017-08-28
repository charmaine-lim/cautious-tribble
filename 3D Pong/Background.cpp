#include "Line.h"
#include "Quadrilateral.h"

#include "Background.h"

// Create the background using the line and quad classes
// Things to note, certain constants have been hard coded and would need to be changed :
// Point of the Top Left Corner of the front most square
// Height and Width of the front most square
// Number of squares to be drawn
// Distance or spacing between squares
Background::Background()
{
	// Initialise the constants

	// choose a point on the top left corner, 
	// choose the width and the height by trial and error or by aspect ratio and camera
	// couldn't be bothered doing a formula for these
	m_topLeftCorner = glm::vec3(-8, 5, 0);
	m_iWidth = 16;
	m_iHeight = 10;

	// distance to move backwards
	m_zDistance = 0;

	//Create all the quads for the background
	CreateQuads();

	//Create the 4 lines
	CreateLines();
}

Background::~Background()
{
	//cleanup vector of pointers
	while (m_vecLines.size() > 0)
	{
		Line* pLine = m_vecLines[m_vecLines.size() - 1];
		m_vecLines.pop_back();
		delete pLine;
	}

	while (m_vecQuads.size() > 0)
	{
		Quadrilateral* pQuad = m_vecQuads[m_vecQuads.size() - 1];
		m_vecQuads.pop_back();
		delete pQuad;
	}
}

void Background::CreateQuads()
{
	//this is the front most quad
	Quadrilateral*  newQuad = new Quadrilateral();

	newQuad->CreateQuad(m_topLeftCorner, m_iWidth, m_iHeight);
	m_vecQuads.push_back(newQuad);

	//make a number of these quads by using the first quad and moving it back a certain z distance
	//doing this means you don't need to resize the quad, you just keep moving it back.
	for (int i = 0; i < 10; i++)
	{
		// 1 is the spacing between the quads
		m_zDistance += 1;	//move back some more

		//for debugging
		//std::cout << zDistance << std::endl;

		//top left corner point remains the same as the original quad, except for the Z value
		glm::vec3 newTopLeftCorner = m_topLeftCorner - glm::vec3(0, 0, m_zDistance);  //moving the quad back a certain distance

		newQuad->CreateQuad(newTopLeftCorner, m_iWidth, m_iHeight);
		m_vecQuads.push_back(newQuad);

		//std::cout << newTopLeftCorner.x << std::endl;
	}
}

//Create 4 lines to join the corners of the quads
void Background::CreateLines()
{
	//Calculate the corner points of the front most quad and the back most quad
	glm::vec3 topLeftFront(m_topLeftCorner);
	glm::vec3 topLeftBack(m_topLeftCorner - glm::vec3(0, 0, m_zDistance));

	glm::vec3 topRightFront(m_topLeftCorner + glm::vec3(m_iWidth, 0, 0));
	glm::vec3 topRightBack(topRightFront - glm::vec3(0, 0, m_zDistance));

	glm::vec3 bottomLeftFront(m_topLeftCorner - glm::vec3(0, m_iHeight, 0));
	glm::vec3 bottomLeftBack(bottomLeftFront - glm::vec3(0, 0, m_zDistance));

	glm::vec3 bottomRightFront(m_topLeftCorner + glm::vec3(m_iWidth, -m_iHeight, 0));
	glm::vec3 bottomRightBack(bottomRightFront - glm::vec3(0, 0, m_zDistance));

	//Create the 4 lines connecting the front quad to the back quad using the corner points
	m_vecLines.push_back(new Line(topLeftFront, topLeftBack));
	m_vecLines.push_back(new Line(topRightFront, topRightBack));
	m_vecLines.push_back(new Line(bottomLeftFront, bottomLeftBack));
	m_vecLines.push_back(new Line(bottomRightFront, bottomRightBack));
}

void Background::Render(Camera& camera)
{
	for (auto itr : m_vecQuads)
	{
		itr->Render(camera);
	}

	for (auto itr : m_vecLines)
	{
		itr->Render(camera);
	}
}
