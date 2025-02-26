#pragma once

struct INFO
{
    char    szName[32];
    int     iHp;
    int     iAttack;
};

class CCharacter
{
public:
    CCharacter();
    CCharacter(const char* pName, int iHp, int iAttack);
    virtual ~CCharacter();

public:
    virtual void Initialize();
    virtual void Update();
    virtual void Release();

public:
    const char* GetName() const { return m_info.szName; }
    const int& GetHP() const { return m_info.iHp; }
    const int& GetAttack() const { return m_info.iAttack; }

    void TakeDamage(int _iAttack) { m_info.iHp -= _iAttack; }

public:
    virtual void Render();

protected:
    INFO                m_info;
};

