#pragma once

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Release();

public:
	void EnterShop();

private:
	class CCharacter* m_pPlayer;
	class CField* m_pField;

	class CShop* m_pLowLevelShop;
	class CShop* m_pMidLevelShop;
	class CShop* m_pHighLevelShop;
};

