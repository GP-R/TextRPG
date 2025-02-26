#include "pch.h"
#include "CShop.h"
#include "CItem.h"

#include "Define.h"

CShop::CShop()
{
}

CShop::CShop(const char* pName, vector<CItem*>* vItems)
{
	strcpy_s(m_sName, sizeof(m_sName), pName);
	m_vItemContainer = *vItems;
}

CShop::~CShop()
{
    Release();
}

void CShop::Initialize()
{
}

void CShop::Update()
{
    int		iInput(0);

    while (true)
    {
        system("cls");
        cout << "[ID]\t" << "아이템 이름(희귀도)\t" << "가격\t" << "아이템 설명" << endl;
        for (CItem* item : m_vItemContainer)
        {
            item->PrintItem();
        }
        cout << "구매할 아이템의 번호(나가기 -1) : ";
        cin >> iInput;
        if (iInput == -1)
        {
            return;
        }


    }
}

void CShop::Release()
{
    for (CItem* item : m_vItemContainer)
    {
        SAFE_DELETE(item);
    }
}
