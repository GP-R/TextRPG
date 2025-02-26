#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
	:CCharacter()
{
}

CMonster::CMonster(INFO info)
	: CCharacter(info.szName, info.iHp, info.iAttack)
{
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	CCharacter::Initialize();

}

void CMonster::Update()
{
	CCharacter::Update();
}

void CMonster::Release()
{
}
