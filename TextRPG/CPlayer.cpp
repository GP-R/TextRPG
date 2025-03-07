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
	cout << "�÷��̾� m_pPlayerInventory ����" << endl;
	SAFE_DELETE(m_pPlayerInventory);
}

void CPlayer::Select_Job()
{
    int     iInput(0);

    cout << "1. ���� 2. ������ 3. ���� 4. ������ : ";
    cin >> iInput;

	switch (iInput)
	{
	case static_cast<int>(JOBINDEX::WARRIOR):

		strcpy_s(m_info.szName, sizeof(m_info.szName), "����");
		m_info.iHp = 100;
		m_info.iAttack = 10;

		break;

	case static_cast<int>(JOBINDEX::MAGE):
		strcpy_s(m_info.szName, sizeof(m_info.szName), "������");
		m_info.iHp = 100;
		m_info.iAttack = 10;
		break;

	case static_cast<int>(JOBINDEX::THIEF):

		strcpy_s(m_info.szName, sizeof(m_info.szName), "����");
		m_info.iHp = 100;
		m_info.iAttack = 10;
		break;

	}

}
