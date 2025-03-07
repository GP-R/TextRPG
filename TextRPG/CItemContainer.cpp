#include "pch.h"
#include "CItemContainer.h"
#include "CItem.h"

#include "Define.h"

CItemContainer::CItemContainer()
{
	m_iMaxSlotSize = 0;
	m_iSlotSize = 0;
}

CItemContainer::CItemContainer(int iMaxSlotSize)
{
	m_iMaxSlotSize = iMaxSlotSize;
	m_iSlotSize = 0;
}

CItemContainer::~CItemContainer()
{
	Release();
}

void CItemContainer::Initialize()
{
}

void CItemContainer::Update()
{
	
}

void CItemContainer::Release()
{
	for (CItem* item : m_vecItems)
	{
		cout << "������" << "\t" << item->GetItemData().m_sName << "\t" << "CItem �����ϰ� ����" << endl;
		SAFE_DELETE(item);
	}
}

bool CItemContainer::AddItem(const SItemData& itemData, int iCount)
{
	// ���� �� �ִ��� �˻� ���� ������ �������
	for (CItem* temp : m_vecItems)
	{
		if (temp->GetItemData().m_sName == itemData.m_sName)
		{
			if (temp->AddItem(iCount))
			{
				return true;
			}
			return false;
		}
	}

	if (m_iMaxSlotSize > m_iSlotSize)
	{
		CItem* item = new CItem(itemData, iCount);
		item->Initialize();
		m_vecItems.push_back(item);
		++m_iSlotSize;
		return true;
	}

	return false;
}

bool CItemContainer::RemoveItem(int iIndex, int iCount)
{
	return false;
}

void CItemContainer::Render()
{
	for (size_t i = 0; i < m_vecItems.size(); ++i)
	{
		const SItemData& itemData = m_vecItems[i]->GetItemData();
		cout << "[" << i + 1 << "]" << "\t";
		cout << itemData.m_sName << "\t";
		cout << itemData.ToStringRairity(itemData.m_eItemRarity) << "\t";
		cout << itemData.m_iPrice << "\t";
		cout << itemData.m_sDescription << "\t";
		cout << endl;
	}
}
