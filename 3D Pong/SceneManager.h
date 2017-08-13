//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: SceneManager.h
// Description	: Scene Manager declaration file.
// Authors		: Charmaine Lim and Cameron Peet
// Mail			: Cameron.Peet@mediadesign.school.nz
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once
#include "Scene.h"

#include <ctime>
#include <iostream>
#include <vector>
#include <map>

//Scene manager
class CSceneManager
{
public:
	~CSceneManager();

	// Singleton Methods
	static CSceneManager& GetInstance();
	static void DestroyInstance();
	bool Initialise();
	CScene* GetScene() { return m_pSelectedScene; };
	CScene* m_pSelectedScene;
	bool SelectScene(std::string _strSceneName);

	bool InitFmod();
	const bool LoadAudio();

private:
	CSceneManager();
	CSceneManager(const CSceneManager& _kr);
	CSceneManager& operator= (const CSceneManager& _kr);

	std::map<std::string, CScene* > m_pSceneMap;
	bool m_bInit;
protected:

	// Singleton Instance
	static CSceneManager* s_pGame;

private:

	GLfloat m_deltatime;
	GLuint m_program;
	GLfloat prevTime = 0.0f;

};