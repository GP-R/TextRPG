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
        cout << "[ID]\t" << "������ �̸�(��͵�)\t" << "����\t" << "������ ����" << endl;
        for (CItem* item : m_vItemContainer)
        {
            item->PrintItem();
        }
        cout << "������ �������� ��ȣ(������ -1) : ";
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
