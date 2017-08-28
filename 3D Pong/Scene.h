//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Scene.h
// Description	: Scene declaration file.
// Authors		: Charmaine Lim 
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once

#include "Model.h"
#include "Camera.h"
//#include "Entity.h"
#include "TextLabel.h"

//Local Network Includes


class CScene
{
public:
	CScene() {};
	~CScene() {};

public:
	virtual void Init() = 0;
	virtual void Update(float fDeltaTime) = 0;
	virtual void Render(GLuint program, Camera& camera) = 0;
	virtual void PassiveMotion(int x, int y) = 0;
	virtual void Mouse(int button, int state, int x, int y) = 0;
	virtual void KeyboardDown(unsigned char c, int x, int y) = 0;
	virtual void KeyboardUp(unsigned char c, int x, int y) = 0;
	//virtual void NetworkProcess() = 0;
	virtual void Reshape(int width, int height) = 0;

protected:
	//Read from right-left Vector of "objects" pointers.
	//std::vector<CEntity*> m_pPlayerVector;
	std::vector<TextLabel*> m_pTextVector;
	std::vector<Model*> m_pModelVector;

};
