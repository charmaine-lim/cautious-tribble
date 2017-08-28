//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Player.h
// Description	: Player declaration file.
// Authors		: Charmaine Lim
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once
#if !defined(__PADDLE_H__)
#define __PADDLE_H__

// Library Includes

// Local Includes
#include "entity.h"

// Types
class Quadrilateral;

// Constants

// Prototypes
class CPlayer //: public CEntity
{
	// Member Functions
public:
	CPlayer();
	/*virtual*/ ~CPlayer();

	/*virtual*/ bool Initialise();

	/*virtual*/ void Draw(Camera& camera);
	/*virtual*/ void Process(float _fDeltaTick, glm::vec3 _move);

	bool CheckSprite(int _iResourceID, int _iMaskResourceID);

	void DestroyBullet();
	//CBullet* GetBullet() const;

	void SetShipSpeed(float _fSpeed);

	float GetBulletSpeed() const;
	void SetBulletSpeed(float _fSpeed);

	void SetHit(bool _b);
	bool IsHit() const;

private:
	CPlayer(const CPlayer& _kr);
	CPlayer& operator= (const CPlayer& _kr);

	// Member Variables
private:
	//CBullet* m_pBullet;
	float m_fSpeed;
	float m_fBulletSpeed;
	bool m_bCanShoot;
	bool m_bHit;

	Quadrilateral*  m_paddle;
	glm::vec3 m_position;
};

#endif    // __PADDLE_H__


