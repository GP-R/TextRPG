#include "pch.h"
#include "CMainGame.h"
#include "CField.h"
#include "CPlayer.h"
#include "CShop.h"
#include "CItem.h"
#include "CPlayerInventory.h"

#include "Define.h"

CMainGame::CMainGame()
{
    m_pField = nullptr;
    m_pPlayer = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
    if (!m_pPlayer)
    {
        m_pPlayer = new CPlayer;
        m_pPlayer->Initialize();
        CPlayer* pPlayer = dynamic_cast<CPlayer*>(m_pPlayer);
        if (pPlayer)
        {
            pPlayer->Select_Job();
        }
    }

    if (!m_pField)
    {
        m_pField = new CField;
        m_pField->Initialize();
        m_pField->Set_Player(m_pPlayer);
    }

    if (!m_pLowLevelShop)
    {
        m_pLowLevelShop = new CShop{"Low Level Shop" };
        m_pLowLevelShop->Initialize();
        vector<SItemData> items = 
        {
            {1,"Low Meet",EItemType::CONSUME, EItemRarity::LOW, "+HP 50", 10, 99},
            {2,"Low Chicken",EItemType::CONSUME, EItemRarity::LOW, "+HP 100", 20, 99}
        };
        m_pLowLevelShop->AddShopItem(items);
    }

    if (!m_pMidLevelShop)
    {
        m_pMidLevelShop = new CShop{ "Mid Level Shop" };
        m_pMidLevelShop->Initialize();
        vector<SItemData> items =
        {
            {1,"Mid Meet",EItemType::CONSUME, EItemRarity::MID, "+HP 200", 100, 99},
            {2,"Mid Chicken",EItemType::CONSUME, EItemRarity::MID, "+HP 300", 150, 99}
        };
        m_pMidLevelShop->AddShopItem(items);
        
    }

    if (!m_pHighLevelShop)
    {
        m_pHighLevelShop = new CShop{ "High Level Shop" };
        m_pHighLevelShop->Initialize();
        vector<SItemData> items =
        {
            {1,"High Meet",EItemType::CONSUME, EItemRarity::HIGH, "+HP 400", 200, 99},
            {2,"High Chicken",EItemType::CONSUME, EItemRarity::HIGH, "+HP 500", 300, 99}
        };
        m_pHighLevelShop->AddShopItem(items);

    }
}

void CMainGame::Update()
{
    int		iInput(0);
    CPlayer* pPlayer = dynamic_cast<CPlayer*>(m_pPlayer);

    while (true)
    {
        system("cls");

        m_pPlayer->Render();

        cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 종료 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            if (m_pField)
            {
                m_pField->Update();
            }

            break;

        case 2:
            EnterShop();
            break;

        case 3 :
            if (pPlayer)
            {
                pPlayer->GetPlayerInventory()->Update();
            }
            break;

        case 4:
            return;
        }

        system("pause");
    }
}

void CMainGame::Release()
{
    cout << "Character" << "\t" << "m_pPlayer" << "\t" << "삭제" << endl;
    SAFE_DELETE(m_pPlayer);
    cout << "Character" << "\t" << "m_pField" << "\t" << "삭제" << endl;
    SAFE_DELETE(m_pField);
    cout << "Character" << "\t" << "m_pLowLevelShop" << "\t" << "삭제" << endl;
    SAFE_DELETE(m_pLowLevelShop);
    cout << "Character" << "\t" << "m_pMidLevelShop" << "\t" << "삭제" << endl;
    SAFE_DELETE(m_pMidLevelShop);
    cout << "Character" << "\t" << "m_pHighLevelShop" << "\t" << "삭제" << endl;
    SAFE_DELETE(m_pHighLevelShop);
}

void CMainGame::EnterShop()
{
    int		iInput(0);

    while (true)
    {
        system("cls");

        cout << "1.초급 상점 2. 중급 상점 3. 고급 상점 4. 나가기:";
        cin >> iInput;
        switch (iInput)
        {
        case 1:
            if (m_pLowLevelShop)
            {
                m_pLowLevelShop->SetInteractor(m_pPlayer);
                m_pLowLevelShop->Update();
            }
            break;
        case 2:
            if (m_pMidLevelShop)
            {
                m_pMidLevelShop->SetInteractor(m_pPlayer);
                m_pMidLevelShop->Update();
            }
            break;
        case 3:
            if (m_pHighLevelShop)
            {
                m_pHighLevelShop->SetInteractor(m_pPlayer);
                m_pHighLevelShop->Update();
            }
            break;
        case 4:
            return;
        }
    }
}

