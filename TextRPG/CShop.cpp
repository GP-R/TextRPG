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
        cout << "구매할 아이템의 번호(0 나가기) : ";
        cin >> iInput;
        if (iInput == 0)
        {
            return;
        }

        // TODO : Inventory끼리 원본 전달 Or Copy 전달 구현 필요해보임
        if (iInput >= 1 && iInput <= m_pItemContainer->GetItemContainer().size())
        {
            if (m_pInteractor)
            {
                CPlayer* player = dynamic_cast<CPlayer*>(m_pInteractor);
                if (player)
                {
                    player->GetPlayerInventory()->AddItem(m_pItemContainer->GetItemContainer()[iInput - 1]->GetItemData());

                    cout << "아이템 구매 완료" << endl;
                    system("pause");
                }

            }
        }
    }
}

void CShop::Release()
{
    cout << "상점" << "\t" << m_sName << "\t" << "m_pItemContainer 삭제" << endl;
    SAFE_DELETE(m_pItemContainer);
}

void CShop::Render()
{
    cout << m_sName << endl;
    cout << "[순서]\t" << "아이템 이름\t" << "희귀도\t" << "가격\t" << "아이템 설명" << endl;
    m_pItemContainer->Render();
}

void CShop::AddShopItem(const vector<SItemData>& vecItems)
{
    for (const SItemData& item : vecItems)
    {
        m_pItemContainer->AddItem(item);
    }
}
