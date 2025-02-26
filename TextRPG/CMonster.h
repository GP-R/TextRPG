#pragma once

#include "CCharacter.h"

class CMonster : public CCharacter
{
public:
    CMonster();
    CMonster(INFO info);
    virtual ~CMonster();

public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Release() override;
};

