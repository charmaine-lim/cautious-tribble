//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Level.h
// Description	: Level declaration file.
// Authors		: Charmaine Lim
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once

#if !defined(__LEVEL_H__)
#define __LEVEL_H__

// Library Includes
#include <vector>
#include <string>

// Local Includes
#include "glew\glew.h"

// Types

// Constants

// Prototypes
class CBall;
class CPlayer;
class COpponent;
//class CBarrier;
//class CFPSCounter;
//class CPlaceHolder;

class CLevel
{
	// Member Functions
public:
	CLevel();
	~CLevel();

	bool Initialise(int _iWidth, int _iHeight);

	void Draw(GLuint program, Camera& camera);
	void Process(float _fDeltaTick, glm::vec3 _move);

	void SetLives(int _iLives);

	void ResetLevel();
	void NextLevel();
	void SetAlienShipSpeed(float _fSpeed);
	void SetAlienBulletSpeed(float _fSpeed);

	void ResetScore();
	int GetScore() const;

protected:
	void ProcessPlayerBulletCollision();
	void ProcessAlienBulletCollision();

	void ProcessCheckForWin();

	void UpdateScoreText();
	void DrawScore();

public:
	CPlayer* GetPlayer() const;

protected:
	int GetAliensRemaining() const;
	void SetAliensRemaining(int _i);

private:
	CLevel(const CLevel& _kr);
	CLevel& operator= (const CLevel& _kr);

	// Member Variables
protected:
	CPlayer* m_pPlayer;
	//std::vector<CAlien*> m_aliens[11];
	//CAlien* m_pSpecialAlien;
	bool m_bSpecialAlien;

	//std::vector<CBullet*> m_vecEnemyBullets;

	//CFPSCounter* m_fpsCounter;

	std::string m_strScore;

	int m_iWidth;
	int m_iHeight;

	int m_iAliensRemaining;

	static int m_iPlayerLives;

	int m_iLowestAlien[10];

private:
	int m_iPreviousAlienShipSpeed;

	static int m_iScore;
	//std::vector<CBarrier*> m_barriers;
	//std::vector<CPlaceHolder*> m_lifeIcons;

};

#endif    // __LEVEL_H__
