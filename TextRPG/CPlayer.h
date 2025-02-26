#pragma once
#include "CCharacter.h"

enum class JOBINDEX 
{ 
    WARRIOR = 1,
    MAGE,
    THIEF,
    JOB_END
};

class CPlayer : public CCharacter
{
public:
    CPlayer();
    ~CPlayer();

    void SetHP(int value) { m_info.iHp = value; }
public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Release() override;
    
public:
    void Select_Job();
};

