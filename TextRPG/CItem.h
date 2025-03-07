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
public:
	int m_iId;
	string m_sName;
	EItemType m_eItemType;
	EItemRarity m_eItemRarity;
	string m_sDescription;
	int m_iPrice;
	int m_iMaxStackCount;

public:
	string ToStringRairity (EItemRarity type) const
	{
		if (type == EItemRarity::LOW)
		{
			return "하급";
		}
		else if (type == EItemRarity::MID)
		{
			return "중급";
		}
		else if (type == EItemRarity::HIGH)
		{
			return "상급";
		}
		return "";
	}
};

class CItem
{
public:
	CItem();
	CItem(const SItemData& itemData, int iCount);
	virtual ~CItem();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Release();

public:
	inline const SItemData& GetItemData() const { return m_sItemData; }
	inline const int& GetStackCount() const { return m_iStackCount; }

public:
	virtual void Use(class CCharacter* User);
	bool AddItem(int iCount);

protected:
	SItemData m_sItemData;
	int m_iStackCount;
};

