//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: SceneManager.cpp
// Description	: Scene Manager implementation file.
// Authors		: Charmaine Lim and Cameron Peet
// Mail			: Cameron.Peet@mediadesign.school.nz
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once
#include "SceneManager.h"
#include "Menu.h"
//#include "Game.h"

#include "fmod/fmod.hpp"
using namespace FMOD;
System* audioMgr;
Sound* menuMusic;
Sound* gameMusic;
Channel* channel;

CSceneManager* CSceneManager::s_pGame = 0;

CSceneManager::CSceneManager()
{

}

CSceneManager::~CSceneManager()
{
	if (s_pGame != 0)
	{
		DestroyInstance();
	}
}
CSceneManager& CSceneManager::GetInstance()
{
	if (s_pGame == 0)
	{
		s_pGame = new CSceneManager;
	}
	return (*s_pGame);
}
void CSceneManager::DestroyInstance()
{
	delete s_pGame;
	s_pGame = 0;
}

const bool CSceneManager::LoadAudio()
{
	FMOD_RESULT result;

	result = audioMgr->createSound("Assets/Audio/ImitationGame.mp3", FMOD_DEFAULT, 0, &gameMusic);
	result = audioMgr->createSound("Assets/Audio/TimeHansZimmer.mp3", FMOD_DEFAULT, 0, &menuMusic);

	gameMusic->setMode(FMOD_LOOP_NORMAL);
	menuMusic->setMode(FMOD_LOOP_NORMAL);

	return true;
}

bool CSceneManager::InitFmod()
{
	FMOD_RESULT result;

	result = System_Create(&audioMgr);
	if (result != FMOD_OK) return false;

	result = audioMgr->init(50, FMOD_INIT_NORMAL, 0);
	if (result != FMOD_OK) return false;

	return true;
}

bool CSceneManager::Initialise()
{
	if (!m_bInit)
	{
		//m_pSceneMap.insert(std::pair<std::string, CScene*>("Game", CGame::GetInstance()));
		//m_pSelectedScene = m_pSceneMap.find("Game")->second;
		//m_pSelectedScene->Init();

		m_pSceneMap.insert(std::pair<std::string, CScene*>("Menu", new CMenu()));
		m_pSelectedScene = m_pSceneMap.find("Menu")->second;
		m_pSelectedScene->Init();

		InitFmod();
		LoadAudio();
		//Channel* channel;

		audioMgr->playSound(menuMusic, 0, false, &channel);

		return true;
	}
	else
	{
		return false;
	}
	return false;
}




bool CSceneManager::SelectScene(std::string _strSceneName)
{
	auto itr = m_pSceneMap.find(_strSceneName);
	if (itr == m_pSceneMap.end())
	{
		return false;
	}
	else
	{
		m_pSelectedScene = itr->second;


		if (_strSceneName == "Menu")
		{
			channel->stop();
			audioMgr->playSound(menuMusic, 0, false, &channel);
		}
		if (_strSceneName == "Game")
		{
			channel->stop();
			audioMgr->playSound(gameMusic, 0, false, &channel);
		}
		return true;
	}
}