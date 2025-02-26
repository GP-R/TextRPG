#include "pch.h"
#include "CItem.h"

CItem::CItem()
{
}

CItem::CItem(SItemData data)
{
	m_sItemData = data;
}

CItem::~CItem()
{
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

void CItem::PrintItem()
{
	string sRarity;
	if (m_sItemData.m_eItemRarity == EItemRarity::LOW)
	{
		sRarity = "하급";
	}
	else if (m_sItemData.m_eItemRarity == EItemRarity::MID)
	{
		sRarity = "중급";
	}
	else if (m_sItemData.m_eItemRarity == EItemRarity::HIGH)
	{
		sRarity = "상급";
	}
	cout << "[" << m_sItemData.m_iId << "] " << m_sItemData.m_sName << "(" << sRarity << ") : " << m_sItemData.m_iPrice << endl;
}

void CItem::Use(CCharacter* User)
{
}
