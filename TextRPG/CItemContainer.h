#pragma once

struct SItemData;
class CItem;

class CItemContainer
{
public:
	CItemContainer();
	CItemContainer(int iMaxSlotSize);
	virtual ~CItemContainer();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Release();

public:
	const vector<CItem*>& GetItemContainer() const { return m_vecItems; }

public:
	bool AddItem(const SItemData& itemData, int iCount = 1);
	bool RemoveItem(int iIndex, int iCount = 1);

	virtual void Render();

protected:
	int m_iSlotSize;
	int m_iMaxSlotSize;
	vector<CItem*> m_vecItems;
};

