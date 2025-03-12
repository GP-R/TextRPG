#include "pch.h"
#include "CCharacter.h"

CCharacter::CCharacter()
{

}

CCharacter::CCharacter(const char* pName, int iHp, int iAttack)
{
	m_info.strName = pName;
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
	cout << "이름 : " << m_info.strName << endl;
	cout << "체력 : " << m_info.iHp << "\t공격력 : " << m_info.iAttack << endl;
}
