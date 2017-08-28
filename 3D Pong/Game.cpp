//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Game.cpp
// Description	: Game implementation file.
// Authors		: Charmaine Lim 
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

// Library Includes
#include <algorithm>

// Local Includes
#include "Background.h"
//#include "Clock.h"
#include "Level.h"
//#include "BackBuffer.h"
#include "utils.h"
//#include "resource.h"

// This Include
#include "Game.h"
#include "SceneManager.h"
//#include "Enemy.h"

// Static Variables
CGame* CGame::s_pGame = 0;

#include "fmod/fmod.hpp"
using namespace FMOD;
System* audioMgrShoot;
Sound* hitSound;
Sound* shootSound;

CGame::CGame()
	: m_pLevel(0)
	, m_iCurrentLevel(0)
	, m_iCurrentScore(0)
	, m_iLives(3)
{

}

CGame::~CGame()
{
	delete m_pLevel;
	m_pLevel = 0;

	delete m_pBackground;
	m_pBackground = 0;
}



void CGame::Init()
{
	//m_pQuad = new Quadrilateral();
	m_pBackground = new Background();

	m_pLevel = new CLevel();
	m_pLevel->Initialise(800, 600);

	/*m_pThisPlayer = new CEntity(0, 0, 0.0);
	m_pThisPlayer->SetPosition(glm::vec3(0.0f, 0.5f, 0.5f));
	m_pPlayerVector.push_back(m_pThisPlayer);

	m_pPlatform = new CModel(QUAD, "Assets/Textures/Crate.jpg");
	m_pPlatform->Initialise();
	m_pPlatform->m_Position = glm::vec3(0, 0, 0);
	m_pPlatform->m_Scale = glm::vec3(12, 12, 0);
	m_pPlatform->m_Rotation = glm::rotate(m_pPlatform->m_Rotation, glm::radians(90.0f), glm::vec3(1.0f, 0, 0));
	m_pModelVector.push_back(m_pPlatform);*/

	m_pTextVector.push_back(new TextLabel("Score: ", "Assets/Fonts/waltographUI.ttf"));
	m_pTextVector[0]->setPosition(glm::vec3((20), Utils::HEIGHT - m_pTextVector[0]->height - 10, 10));
	m_pTextVector[0]->setColor(glm::vec3(0.0f, 1.0f, 1.0f));
	m_pTextVector[0]->setScale(0.5f);
	m_pTextVector[0]->setActive(false);
	m_pTextVector[0]->setButton(false);

	//m_pTextVector.push_back(new TextLabel("Lives: ", "Assets/Fonts/waltographUI.ttf"));
	//m_pTextVector[1]->setPosition(glm::vec3(Utils::WIDTH - m_pTextVector[1]->width - 20, Utils::HEIGHT - m_pTextVector[1]->height - 10, 10));
	//m_pTextVector[1]->setColor(glm::vec3(0.0f, 1.0f, 1.0f));
	//m_pTextVector[1]->setScale(0.5f);
	//m_pTextVector[1]->setActive(false);
	//m_pTextVector[1]->setButton(false);

	m_pTextVector.push_back(new TextLabel("Level: ", "Assets/Fonts/waltographUI.ttf"));
	//m_pTextVector[2]->setPosition(glm::vec3(400, Utils::HEIGHT - m_pTextVector[1]->height - 10, 10));
	m_pTextVector[1]->setPosition(glm::vec3(Utils::WIDTH - m_pTextVector[1]->width - 20, Utils::HEIGHT - m_pTextVector[1]->height - 10, 10));
	m_pTextVector[1]->setColor(glm::vec3(0.0f, 1.0f, 1.0f));
	m_pTextVector[1]->setScale(0.5f);
	m_pTextVector[1]->setActive(false);
	m_pTextVector[1]->setButton(false);

	m_pTextVector.push_back(new TextLabel("Bonus: ", "Assets/Fonts/waltographUI.ttf"));
	//m_pTextVector[2]->setPosition(glm::vec3(Utils::WIDTH - m_pTextVector[1]->width - 20, Utils::HEIGHT - m_pTextVector[1]->height - 700, 10));
	m_pTextVector[2]->setPosition(glm::vec3(Utils::WIDTH - m_pTextVector[1]->width - 20, Utils::HEIGHT - 760, 10));
	m_pTextVector[2]->setColor(glm::vec3(0.0f, 1.0f, 1.0f));
	m_pTextVector[2]->setScale(0.5f);
	m_pTextVector[2]->setActive(false);
	m_pTextVector[2]->setButton(false);

	m_iBonus = 3000;
	SetCurrentScore(0);
	SetCurrentLevel(0);
	SetLives(3);
	InitialiseLevelInfo();
	StartNewGame();

	InitFmod();
	LoadAudio();
}

void CGame::Render(GLuint program, Camera& camera)
{
	m_camera = camera;

	m_pBackground->Render(camera);

	//for (auto itr : m_pModelVector)
	//{
	//	itr->Render(program, camera);
	//}
	//for (auto itr : m_pPlayerVector)
	//{
	//	itr->Render(program, camera);
	//}


	m_pLevel->Draw(program, camera);

	for (auto itr : m_pTextVector)
	{
		itr->Render(camera);
	}

	//m_pQuad->Render(camera);
}

void CGame::Update(float fDeltaTime)
{
	//m_pThisPlayer->Translate(glm::vec3(g_D - g_A, 0, g_S - g_W) * (m_fMaxSpeed * fDeltaTime));
	m_pLevel->Process(fDeltaTime, glm::vec3(g_D - g_A, g_W - g_S, 0));

	std::string _strScore = "Score: ";
	//_strScore += ToString(m_pLevel->GetPlayerScore());
	m_pTextVector[0]->setText(_strScore);

	std::string _strLives = "Lives: ";
	//_strLives += ToString(m_pLevel->GetPlayerLives());
	//m_pTextVector[1]->setText(_strLives);

	std::string _strLevel = "Level: ";
	//_strLevel += ToString(m_iCurrentLevel);
	//_strLevel += " - ";
	//_strLevel += static_cast<ENEMY_TYPE> (m_iCurrentLevel);
	_strLevel += ToString(m_iCurrentLevel + 1);
	//if (m_iCurrentLevel < 11)
	//{
	//	_strLevel += AI[m_iCurrentLevel];
	//}
	//else
	//{
	//	_strLevel += "Wander";
	//}
	m_pTextVector[1]->setText(_strLevel);

	std::string _strBonus = "Bonus: ";
	_strBonus += ToString(m_iBonus);
	m_pTextVector[2]->setText(_strBonus);
}

void CGame::PassiveMotion(int x, int y)
{
	//m_pQuad->CreateQuad(glm::vec3(x, y, 0), 1, 1);
}

void CGame::Mouse(int button, int state, int x, int y)
{
	//m_pQuad->CreateQuad(glm::vec3(x, y, 0), 1, 1);
}

void CGame::Reshape(int w, int h)
{
	m_pTextVector[0]->setPosition(glm::vec3((20), Utils::HEIGHT - m_pTextVector[0]->height - 10, 10));
	m_pTextVector[1]->setPosition(glm::vec3(Utils::WIDTH - m_pTextVector[1]->width - 20, Utils::HEIGHT - m_pTextVector[1]->height - 10, 10));
	//m_pTextVector[2]->setPosition(glm::vec3(400, Utils::HEIGHT - m_pTextVector[1]->height - 10, 10));
	m_pTextVector[2]->setPosition(glm::vec3(Utils::WIDTH - m_pTextVector[1]->width - 20, Utils::HEIGHT - 760, 10));
}

void CGame::KeyboardDown(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 'w':
	case 'W':
		g_W = 1;
		break;
	case 'a':
	case 'A':
		g_A = 1;
		break;
	case 's':
	case 'S':
		g_S = 1;
		break;
	case 'd':
	case 'D':
		g_D = 1;
		break;
		//charmaine - used ijkl to fire, arrows may also be used but the arrow key doesn't convert to a char
		// so another way could be used to store the arrow key input
	case 'i':
	case 'I':
		g_I = 1;
		Channel* pChannel;
		audioMgrShoot->playSound(shootSound, 0, false, &pChannel);
		break;
	case 'j':
	case 'J':
		g_J = 1;
		audioMgrShoot->playSound(shootSound, 0, false, &pChannel);
		break;
	case 'k':
	case 'K':
		g_K = 1;
		audioMgrShoot->playSound(shootSound, 0, false, &pChannel);
		break;
	case 'l':
	case 'L':
		g_L = 1;
		audioMgrShoot->playSound(shootSound, 0, false, &pChannel);
		break;
	default:
		break;
	}
}

void CGame::KeyboardUp(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 'w':
	case 'W':
		g_W = 0;
		break;
	case 'a':
	case 'A':
		g_A = 0;
		break;
	case 's':
	case 'S':
		g_S = 0;
		break;
	case 'd':
	case 'D':
		g_D = 0;
		break;
		//charmaine
	case 'i':
	case 'I':
		g_I = 0;
		break;
	case 'j':
	case 'J':
		g_J = 0;
		break;
	case 'k':
	case 'K':
		g_K = 0;
		break;
	case 'l':
	case 'L':
		g_L = 0;
		break;
	default:
		break;
	}
}

bool CGame::StartNewGame()
{
	/*m_pLevel = new CLevel();
	m_pLevel->SetGameInstance(s_pGame);
	m_pLevel->SetLevelInfo(m_ClevelInfo);
	m_pLevel->Initialise(1000, 1000);*/

	return true;
}

CGame* CGame::GetInstance()
{
	if (s_pGame == 0)
	{
		s_pGame = new CGame();
	}

	return (s_pGame);
}

void CGame::DestroyInstance()
{
	delete s_pGame;
	s_pGame = 0;
}

void CGame::GameOverWon()
{
	TextLabel* label;
	//string strAI = "You won.";
	//label = new TextLabel(strAI, "Assets/fonts/waltographUI.ttf");
//	label->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
//	label->setColor(glm::vec3(0.0f, 0.0f, 0.0f));
//	label->Render(m_camera);

	Sleep(5000);
	MainMenu();
	//PostQuitMessage(0);
}

void CGame::GameOverLost()
{
	TextLabel* label;
	//string strAI = "You lost.";
	//label = new TextLabel(strAI, "Assets/fonts/waltographUI.ttf");
	//label->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	//label->setColor(glm::vec3(0.0f, 0.0f, 0.0f));
	//label->Render(m_camera);
	//Sleep(5000);
	MainMenu();
}

void CGame::GameOver()
{
	//m_iCurrentLevel = 0;
	//m_iLives = 3;

	//TextLabel* label;
	//string strAI = "Game Over.";
	//label = new TextLabel(strAI, "Assets/fonts/waltographUI.ttf");
	//label->setActive(true);
	//label->setButton(true);
	//label->setPosition(glm::vec3(100.0f, 100.0f, 0.0f));
	//label->setColor(glm::vec3(0.0f, 0.0f, 0.0f));
	//label->Render(m_camera);
	//glutPostRedisplay();
	//Sleep(5000);
	MainMenu();
}

void CGame::MainMenu()
{
	CSceneManager& _rSceneManager = CSceneManager::GetInstance();
	_rSceneManager.SelectScene("Menu");
}

CLevel* CGame::GetLevel()
{
	return (m_pLevel);
}

void CGame::SetLives(int _iLives)
{
	m_iLives = _iLives;
}

int CGame::GetLives()
{
	return m_iLives;
}

void CGame::SetCurrentScore(int _iScore)
{
	m_iCurrentScore = _iScore;
}

int CGame::GetCurrentScore()
{
	return m_iCurrentScore;
}

void CGame::SetCurrentLevel(int _iLevel)
{
	m_iCurrentLevel = _iLevel;
}

int CGame::GetCurrentLevel()
{
	return m_iCurrentLevel;
}

//void CGame::SetLevelInfo(LevelInfo _ClevelInfo)
//{
//	m_ClevelInfo = _ClevelInfo;
//}
//
//LevelInfo CGame::GetLevelInfo()
//{
//	return m_ClevelInfo;
//}
//
//void CGame::LevelComplete()
//{
//	m_iCurrentLevel++;
//	m_pLevel->SetUpNextLevel();
//}

void CGame::IncreaseScore(int _iPoints)
{
	m_iCurrentScore += _iPoints;
}

int CGame::DecrementLives()
{
	if (m_iLives > 0)
	{
		m_iLives--;
	}
	return m_iLives;
}

void CGame::InitialiseLevelInfo()
{
	//m_ClevelInfo.m_fStartMoveDelay = 1.0f;
	//m_ClevelInfo.m_fmoveDelayDecrement = 0.018f;
	//m_ClevelInfo.m_fHorizonalStartSpeed = 7.0f;
	//m_ClevelInfo.m_fHorizontalSpeedMultiplier = 1.0f;
	//m_ClevelInfo.m_fVerticalSpeed = 30.0f;
	//m_ClevelInfo.m_iMysteryInvaderChance = 2;
	//m_ClevelInfo.m_fMoveDelayLowClamp = 1;
	//m_ClevelInfo.m_iStartY = 50;
	////charmaine
	//m_ClevelInfo.m_iMaxPlayerProjectiles = 10;
	//m_ClevelInfo.m_iEnemyFireChance = 1;
	//m_ClevelInfo.m_iMaxEnemyProjectiles = 10;
}

const bool CGame::LoadAudio()
{
	FMOD_RESULT result;

	result = audioMgrShoot->createSound("Assets/Audio/killed.wav", FMOD_DEFAULT, 0, &hitSound);
	result = audioMgrShoot->createSound("Assets/Audio/shoot.wav", FMOD_DEFAULT, 0, &shootSound);

	//gameMusic->setMode(FMOD_LOOP_NORMAL);
	//menuMusic->setMode(FMOD_LOOP_NORMAL);

	return true;
}

bool CGame::InitFmod()
{
	FMOD_RESULT result;

	result = System_Create(&audioMgrShoot);
	if (result != FMOD_OK) return false;

	result = audioMgrShoot->init(50, FMOD_INIT_NORMAL, 0);
	if (result != FMOD_OK) return false;

	return true;
}