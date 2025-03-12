#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
	:CCharacter()
{
}

CMonster::CMonster(INFO info)
	: CCharacter(info.strName.c_str(), info.iHp, info.iAttack)
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
