#pragma once

enum class EItemType
{
	EQUIPMENT = 1,
	CONSUME,
	QUEST,
	TYPE_END
};

enum class EItemRarity
{
	LOW = 1,
	MID,
	HIGH,
	RARITY_END
};

struct SItemData
{
	int m_iId;
	char m_sName[32];
	EItemType m_eItemType;
	EItemRarity m_eItemRarity;
	char m_sDescription[32];
	int m_iPrice;
};

class CItem
{
public:
	CItem();
	CItem(SItemData data);
	virtual ~CItem();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Release();

public:
	virtual void PrintItem();
	virtual void Use(class CCharacter* User);

private:
	SItemData m_sItemData;
};

