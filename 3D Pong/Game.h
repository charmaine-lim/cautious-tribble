//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Game.h
// Description	: Game declaration file.
// Authors		: Charmaine Lim
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once

#include "Scene.h"
//#include "Entity.h"
//#include "LevelInfo.h"

#include "glm/glm.hpp"

#include "Quadrilateral.h"

enum LEVEL_STATE
{
	GetReady,
	Playing,
	NextLife,
	NextLevel,
	GameOver
};

class CLevel;
class Background;

class CGame : public CScene
{
public:


	void Init();
	void Update(float fDeltaTime);
	void Render(GLuint program, Camera& camera);
	//void NetworkProcess() {};
	void PassiveMotion(int x, int y);
	void Mouse(int button, int state, int x, int y);
	void KeyboardDown(unsigned char c, int x, int y);
	void KeyboardUp(unsigned char c, int x, int y);
	void Reshape(int w, int h);

	//lim
	//GLuint Initialise(int _iScenario, CEntity* _pPlayerEntity, Model* _pPlayerModel);
	//void Render();
	void SetTime(GLfloat _deltatime);
	void Update(glm::vec3 _delta, glm::vec3 _fire);
	void InitModels();
	void LoadTextures();

	CLevel* GetLevel();
	void GameOverWon();
	void GameOverLost();

	void SetLives(int _iLives);
	int GetLives();
	void SetCurrentScore(int _iScore);
	int GetCurrentScore();
	void SetCurrentLevel(int _iLevel);
	int GetCurrentLevel();
	//void SetLevelInfo(LevelInfo _ClevelInfo);
	//LevelInfo GetLevelInfo();

	void LoadNextLevel();
	void IncreaseScore(int _iPoints);
	bool StartNewGame();
	void QuitGame();
	void LevelComplete();
	int DecrementLives();
	void GameOver();
	void InitialiseLevelInfo();
	void MainMenu();

	void SetLevelState(LEVEL_STATE _eState)
	{

	}

	// Singleton Methods
	static CGame* GetInstance();
	static void DestroyInstance();

	bool InitFmod();
	const bool LoadAudio();

protected:
	static CGame* s_pGame;

private:
	CGame::CGame();
	CGame::~CGame();

	std::string m_strMenuName;

	//Vector for easier rendering, re-assigned according to menu depth
	//std::vector<TextLabel*>* m_pCurrentMenu = &m_pMainMenu;
	//CEntity* m_pThisPlayer;
	Model* m_pPlatform;
	//Vector for easier rendering
	int g_W, g_A, g_S, g_D;
	int g_I, g_J, g_K, g_L;
	float m_fMaxSpeed = 4.0f;

	//std::map<std::string, CEntity*> m_pPlayers;
	//std::map<std::string, CEntity*> m_pEntities;

	CLevel* m_pLevel;
	LEVEL_STATE m_ELevelState;

	int m_iCurrentLevel;
	int m_iCurrentScore;
	int m_iLives;
	int m_iplayer2lives;
	int m_iBonus;

	//LevelInfo m_ClevelInfo;
	//int m_iWidth;
	//int m_iHeight;
	//string m_sName;

	Camera m_camera;

	Background* m_pBackground;

	Quadrilateral* m_pQuad;
};
