//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// File Name	:	Entity.cpp
// Description	:	Entity implementation file.
// Author		:	Charmaine Lim
// Mail			:   charmaine.lim6440@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "utils.h"

// This Include
#include "entity.h"

// Static Variables

// Static Function Prototypes

// Implementation

CEntity::CEntity()
	: m_fX(0.0f)
	, m_fY(0.0f)
{

}

CEntity::~CEntity()
{
	/*delete m_pSprite;
	m_pSprite = 0;*/
}

bool CEntity::Initialise(glm::vec3 _location, glm::vec3 _velocity)
{
	////if (m_pSprite == nullptr)
	//m_pSprite = new CSprite();

	//VALIDATE(m_pSprite->Initialise(_kiSpriteID, _kiMaskID));

	return (true);
}

void CEntity::Draw(GLuint program, Camera& camera)
{
	/*if (m_bIsActive && !m_bIsHit)
	{
		m_model->Render(program, camera);
	}*/
}

void
CEntity::Process(float _fDeltaTick)
{
	/*m_pSprite->SetX(static_cast<int>(m_fX));
	m_pSprite->SetY(static_cast<int>(m_fY));*/

	//m_pSprite->Process(_fDeltaTick);


	/*m_velocity += m_acceleration * _deltaTime;
	m_velocity = Limit(m_fMaxspeed, m_velocity);
	m_location += m_velocity * _deltaTime;
	m_acceleration *= 0;

	m_model->SetPosition(m_location);*/
}
//
//float
//CEntity::GetX() const
//{
//	return (m_fX);
//}
//
//float
//CEntity::GetY() const
//{
//	return (m_fY);
//}
//
//float
//CEntity::GetWidth() const
//{
//	return (static_cast<float>(m_pSprite->GetWidth()));
//}
//
//float
//CEntity::GetHeight() const
//{
//	return (static_cast<float>(m_pSprite->GetHeight()));
//}
//
//void
//CEntity::SetX(float _f)
//{
//	m_fX = _f;
//}
//
//void
//CEntity::SetY(float _f)
//{
//	m_fY = _f;
//}
//
