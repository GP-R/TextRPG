#include "pch.h"
#include "CPlayerInventory.h"
#include "CItem.h"

CPlayerInventory::CPlayerInventory()
{
}

CPlayerInventory::CPlayerInventory(int iMaxSlotSize)
	:CItemContainer(iMaxSlotSize)
{
}

CPlayerInventory::~CPlayerInventory()
{
	Release();
}

void CPlayerInventory::Initialize()
{
}

void CPlayerInventory::Update()
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		Render();
		cout << "����� ������(������ : 0) : ";
		cin >> iInput;
		if (iInput == 0)
		{
			break;
		}
		if (iInput >=1 && iInput <= m_vecItems.size())
		{
			//m_vecItems[iInput - 1]->Use();
		}
	}
}

void CPlayerInventory::Release()
{
	cout << "Player Inventory ����";
}

void CPlayerInventory::Render()
{
	cout << "[����]\t" << "�������̸�\t" << "��͵�\t" << "����\t" << "�����ۼ���\t" << endl;
	for (size_t i = 0; i < m_vecItems.size(); ++i)
	{
		const SItemData& itemData = m_vecItems[i]->GetItemData();
		cout << "[" << i + 1 << "]" << "\t";
		cout << itemData.m_sName << "\t";
		cout << itemData.ToStringRairity(itemData.m_eItemRarity) << "\t";
		cout << itemData.m_iPrice << "\t";
		cout << itemData.m_sDescription << "\t";
		cout << "		|| ������ ���� : " << m_vecItems[i]->GetStackCount() << "/" << itemData.m_iMaxStackCount << "\t";
		cout << endl;
	}
}
