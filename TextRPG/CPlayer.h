#pragma once
#include "CCharacter.h"

class CItemContainer;

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

public:
    inline CItemContainer* GetPlayerInventory() { return m_pPlayerInventory; }
    inline void SetHP(int value) { m_info.iHp = value; }

public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Release() override;
   
public:
    void Select_Job();

private:
    CItemContainer* m_pPlayerInventory;
};

