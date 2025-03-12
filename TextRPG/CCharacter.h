#pragma once

struct INFO
{
    string    strName;
    int     iHp;
    int     iAttack;

    void Save(ofstream& ofs) const
    {
        size_t nameLen = strName.size();
        ofs.write((char*)&nameLen, sizeof(nameLen));
        ofs.write(strName.c_str(), nameLen);

        ofs.write((char*)&iHp, sizeof(iHp));
        ofs.write((char*)&iAttack, sizeof(iAttack));
    }

    void Load(ifstream& ifs)
    {
        size_t nameLen = 0;
        ifs.read((char*)&nameLen, sizeof(nameLen));
        strName.resize(nameLen);
        ifs.read(&strName[0], nameLen);

        ifs.read((char*)&iHp, sizeof(iHp));
        ifs.read((char*)&iAttack, sizeof(iAttack));
    }
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
    void LoadInfo(const INFO& info) { m_info = info; }
    const INFO& GetInfo() const { return m_info; }

    void TakeDamage(int _iAttack) { m_info.iHp -= _iAttack; }

public:
    virtual void Render();

protected:
    INFO                m_info;
};

