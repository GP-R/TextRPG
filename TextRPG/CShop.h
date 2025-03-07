#pragma once

struct SItemData;

class CShop
{
public:
	CShop();
	CShop(const char* pName);
	virtual ~CShop();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual void Render();

public:
	void SetInteractor(class CCharacter* pCharacter) { m_pInteractor = pCharacter; }

public:
	void AddShopItem(const vector<SItemData>& vecItems);

private:
	class CCharacter* m_pInteractor;
	string m_sName;
	class CItemContainer* m_pItemContainer;
};

