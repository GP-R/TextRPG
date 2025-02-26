#include "pch.h"
#include "CCharacter.h"

CCharacter::CCharacter()
{

}

CCharacter::CCharacter(const char* pName, int iHp, int iAttack)
{
	strcpy_s(m_info.szName, sizeof(m_info.szName), pName);
	m_info.iHp = iHp;
	m_info.iAttack = iAttack;
}

CCharacter::~CCharacter()
{
}

void CCharacter::Initialize()
{
}

void CCharacter::Update()
{
}

void CCharacter::Release()
{
}

void CCharacter::Render()
{
	cout << "=========================================" << endl;
	cout << "�̸� : " << m_info.szName << endl;
	cout << "ü�� : " << m_info.iHp << "\t���ݷ� : " << m_info.iAttack << endl;
}
