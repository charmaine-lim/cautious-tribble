//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Player.cpp
// Description	: Player implementation file.
// Authors		: Charmaine Lim
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//


// Library Includes

// Local Includes
#include "utils.h"

// This Include
#include "player.h"
//#include "Line.h"
#include "Quadrilateral.h"

// Static Variables

// Static Function Prototypes

// Implementation

CPlayer::CPlayer() :
	m_fSpeed(1),
	m_fBulletSpeed(750),
	m_bCanShoot(true),
	m_bHit(false)
{
	m_position = glm::vec3(0, 0, 0);
}

CPlayer::~CPlayer()
{}

bool CPlayer::Initialise() 
{
	glm::vec3 _topLeftCorner = glm::vec3(0, 0, 0);
	int _iWidth = 2;
	int _iHeight = 1;

	m_paddle = new Quadrilateral();
	m_paddle->setIsPaddle(true);
	m_paddle->CreateQuad(_topLeftCorner, _iWidth, _iHeight);
	m_paddle->setColor(glm::vec3(1.0, 0.0, 0.0));


	return (true);
}

void CPlayer::Draw(Camera& camera)
{

	//if (!m_bHit) {

	//	if (m_pBullet != nullptr)
	//		m_pBullet->Draw();

	//	CEntity::Draw();

	//}
	m_paddle->Render(camera);
}

void CPlayer::Process(float _fDeltaTick, glm::vec3 _delta)
{

	if (!m_bHit) {

		/*if (m_bCanShoot && GetAsyncKeyState(VK_SPACE) & 0x8000) {

			m_pBullet = new CBullet();
			m_pBullet->Initialise(0, m_fX, m_fY - 28, GetBulletSpeed());

			m_bCanShoot = false;

		}*/

		//glm::vec3  _location = m_location;
		_delta *= (_fDeltaTick * m_fSpeed);
		m_position += _delta;
		if (m_position.x < 7.0f && m_position.x > -7.0f && m_position.z < 7.0f && m_position.z > -7.0f)
		{
			if (glm::length(_delta) > 0)
			{
				//Translate(_delta);
				m_position += _delta;
			}
		}
		m_paddle->setPosition(m_position);

		/*
		float fHalfPaddleW = m_pSprite->GetWidth() / 2.0f;

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {

			m_pSprite->Deinitialise();
			m_pSprite->Initialise(IDB_SHIP_PLAYER_RIGHT_SPRITE, IDB_SHIP_PLAYER_RIGHT_MASK);
			m_fX += m_fSpeed * _fDeltaTick;

		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {

			m_pSprite->Deinitialise();
			m_pSprite->Initialise(IDB_SHIP_PLAYER_LEFT_SPRITE, IDB_SHIP_PLAYER_LEFT_MASK);
			m_fX -= m_fSpeed * _fDeltaTick;

		}
		else {

			m_pSprite->Deinitialise();
			m_pSprite->Initialise(IDB_SHIP_PLAYER_SPRITE, IDB_SHIP_PLAYER_MASK);

		}*/

		//if (m_fX - fHalfPaddleW <= 0) {

		//	m_fX = fHalfPaddleW;

		//}
		//else if (m_fX + fHalfPaddleW >= 747) {

		//	m_fX = 747 - fHalfPaddleW;

		//}

		//if (m_pBullet != nullptr)
		//	m_pBullet->Process(_fDeltaTick);

		//CEntity::Process(_fDeltaTick);

	}

}

void CPlayer::DestroyBullet() {

	m_bCanShoot = true;
	//m_pBullet = nullptr;

}

//CBullet* CPlayer::GetBullet() const {
//
//	return (m_pBullet);
//
//}

void CPlayer::SetShipSpeed(float _fSpeed) {

	m_fSpeed = _fSpeed;

}

float CPlayer::GetBulletSpeed() const {

	return (m_fBulletSpeed);

}

void CPlayer::SetBulletSpeed(float _fSpeed) {

	m_fBulletSpeed = _fSpeed;

}

void CPlayer::SetHit(bool _b) {

	m_bHit = _b;

}

bool CPlayer::IsHit() const {

	return (m_bHit);

}