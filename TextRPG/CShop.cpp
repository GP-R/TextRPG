#include "pch.h"
#include "CShop.h"
#include "CItem.h"
#include "CPlayer.h"
#include "CItemContainer.h"

#include "Define.h"

CShop::CShop()
{
    m_pInteractor = nullptr;
    m_sName = "";
}

CShop::CShop(const char* pName)
{
    m_sName = pName;
}

CShop::~CShop()
{
    Release();
}

void CShop::Initialize()
{
    m_pItemContainer = new CItemContainer(999);
    m_pItemContainer->Initialize();
}

void CShop::Update()
{
    int		iInput(0);

    while (true)
    {
        system("cls");
        m_pItemContainer->Update();
        Render();
        cout << "������ �������� ��ȣ(0 ������) : ";
        cin >> iInput;
        if (iInput == 0)
        {
            return;
        }

        // TODO : Inventory���� ���� ���� Or Copy ���� ���� �ʿ��غ���
        if (iInput >= 1 && iInput <= m_pItemContainer->GetItemContainer().size())
        {
            if (m_pInteractor)
            {
                CPlayer* player = dynamic_cast<CPlayer*>(m_pInteractor);
                if (player)
                {
                    player->GetPlayerInventory()->AddItem(m_pItemContainer->GetItemContainer()[iInput - 1]->GetItemData());

                    cout << "������ ���� �Ϸ�" << endl;
                    system("pause");
                }

            }
        }
    }
}

void CShop::Release()
{
    cout << "����" << "\t" << m_sName << "\t" << "m_pItemContainer ����" << endl;
    SAFE_DELETE(m_pItemContainer);
}

void CShop::Render()
{
    cout << m_sName << endl;
    cout << "[����]\t" << "������ �̸�\t" << "��͵�\t" << "����\t" << "������ ����" << endl;
    m_pItemContainer->Render();
}

void CShop::AddShopItem(const vector<SItemData>& vecItems)
{
    for (const SItemData& item : vecItems)
    {
        m_pItemContainer->AddItem(item);
    }
}
