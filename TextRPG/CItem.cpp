#include "pch.h"
#include "CItem.h"

CItem::CItem()
{
	m_sItemData = SItemData();
	m_iStackCount = 0;
}

CItem::CItem(const SItemData& data, int iCount)
{
	m_sItemData = data;
	m_iStackCount = iCount;
}

CItem::~CItem()
{
	Release();
}

void CItem::Initialize()
{
}

void CItem::Update()
{
}

void CItem::Release()
{
}

//void CItem::PrintItem()
//{
//	string sRarity;
//	if (m_sItemData.m_eItemRarity == EItemRarity::LOW)
//	{
//		sRarity = "하급";
//	}
//	else if (m_sItemData.m_eItemRarity == EItemRarity::MID)
//	{
//		sRarity = "중급";
//	}
//	else if (m_sItemData.m_eItemRarity == EItemRarity::HIGH)
//	{
//		sRarity = "상급";
//	}
//	cout << "[" << m_sItemData.m_iId << "]" << "\t";
//	cout << m_sItemData.m_sName;
//	cout << "(" << sRarity << ") : " << "\t";
//	cout << m_sItemData.m_iPrice << "\t";
//	cout << m_sItemData.m_sDescription << "\t";
//	cout << endl;
//}

void CItem::Use(CCharacter* User)
{
}

bool CItem::AddItem(int iCount)
{
	if (m_sItemData.m_iMaxStackCount >= m_iStackCount + iCount)
	{
		m_iStackCount += iCount;
		return true;
	}
	return false;
}
