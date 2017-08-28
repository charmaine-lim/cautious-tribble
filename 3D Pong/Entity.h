//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// File Name	: Entity.h
// Description	: Entity declaration file.
// Author		: Charmaine Lim 
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once

#ifndef ENTITY_H
#define ENTITY_H

// Library Includes

// Local Includes
#include "glew/glew.h"
#include "glm/glm.hpp"

// Types

// Constants

// Prototypes
class Camera;

class CEntity
{
	// Member Functions
public:
	CEntity();
	virtual ~CEntity();

	virtual bool Initialise(glm::vec3 _location, glm::vec3 _velocity);

	virtual void Draw(GLuint program, Camera& camera) = 0;
	virtual void Process(GLfloat _fDeltaTick);

	glm::vec3 Update(GLfloat _deltaTime);

	void SetPosition(glm::vec3 _position);
	void SetModelPosition();
	glm::vec3 GetPosition();
	void Translate(glm::vec3 delta);

	//void SetX(float _f);
	//void SetY(float _f);

	//float GetX() const;
	//float GetY() const;

	//float GetHeight() const;
	//float GetWidth() const;

protected:

private:
	CEntity(const CEntity& _kr);
	CEntity& operator= (const CEntity& _kr);

	// Member Variables
public:

protected:
	//CSprite* m_pSprite;

	float m_fX;
	float m_fY;

private:

};

#endif    // __ENTITY_H__

