#pragma once

class CField
{
public:
	CField();
	~CField();

public:
	void	Set_Player(class CCharacter* pCopyPlayer)
	{
		m_pCopyPlayer = pCopyPlayer;
	}

public:
	void	Initialize();
	void	Update();
	void	Release();

private:
	int		Fight();

private:
	class CCharacter* m_pCopyPlayer;
	class CCharacter* m_pMonster;
};

