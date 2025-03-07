#include "pch.h"
#include "CPlayer.h"
#include "CPlayerInventory.h"

#include "Define.h"
CPlayer::CPlayer()
{
	m_pPlayerInventory = nullptr;
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	CCharacter::Initialize();
	m_pPlayerInventory = new CPlayerInventory(5);
	m_pPlayerInventory->Initialize();
}

void CPlayer::Update()
{
	CCharacter::Update();
}

void CPlayer::Release()
{
	cout << "플레이어 m_pPlayerInventory 삭제" << endl;
	SAFE_DELETE(m_pPlayerInventory);
}

void CPlayer::Select_Job()
{
    int     iInput(0);

    cout << "1. 전사 2. 마법사 3. 도적 4. 나가기 : ";
    cin >> iInput;

	switch (iInput)
	{
	case static_cast<int>(JOBINDEX::WARRIOR):

		strcpy_s(m_info.szName, sizeof(m_info.szName), "전사");
		m_info.iHp = 100;
		m_info.iAttack = 10;

		break;

	case static_cast<int>(JOBINDEX::MAGE):
		strcpy_s(m_info.szName, sizeof(m_info.szName), "마법사");
		m_info.iHp = 100;
		m_info.iAttack = 10;
		break;

	case static_cast<int>(JOBINDEX::THIEF):

		strcpy_s(m_info.szName, sizeof(m_info.szName), "도적");
		m_info.iHp = 100;
		m_info.iAttack = 10;
		break;

	}

}
