#include "pch.h"
#include "CMainGame.h"
#include "CField.h"
#include "CPlayer.h"
#include "CShop.h"
#include "CItem.h"

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
        vector<CItem*> items = 
        {
            {   new CItem{{1,"Low Meet",EItemType::CONSUME, EItemRarity::LOW, "+HP 50", 10}}        },
            {   new CItem{{2,"Low Chicken",EItemType::CONSUME, EItemRarity::LOW, "+HP 100", 20}}    }
        };
        m_pLowLevelShop = new CShop{"Low Level Shop",&items };
        m_pLowLevelShop->Initialize();
    }

    if (!m_pMidLevelShop)
    {
        vector<CItem*> items =
        {
            {   new CItem{{1,"Mid Meet",EItemType::CONSUME, EItemRarity::LOW, "+HP 50", 10}}        },
            {   new CItem{{2,"Mid Chicken",EItemType::CONSUME, EItemRarity::LOW, "+HP 100", 20}}    }
        };
        m_pMidLevelShop = new CShop{ "Low Level Shop",&items };
        m_pMidLevelShop->Initialize();
    }

    if (!m_pHighLevelShop)
    {
        vector<CItem*> items =
        {
            {   new CItem{{1,"High Meet",EItemType::CONSUME, EItemRarity::LOW, "+HP 50", 10}}        },
            {   new CItem{{2,"High Chicken",EItemType::CONSUME, EItemRarity::LOW, "+HP 100", 20}}    }
        };
        m_pHighLevelShop = new CShop{ "Low Level Shop",&items };
        m_pHighLevelShop->Initialize();
    }
}

void CMainGame::Update()
{
    int		iInput(0);

    while (true)
    {
        system("cls");

        m_pPlayer->Render();

        cout << "1. 사냥터 2. 상점 3. 종료 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            if (m_pField)
                m_pField->Update();

            break;

        case 2:
            EnterShop();
            break;

        case 3:
            return;
        }

        system("pause");
    }
}

void CMainGame::Release()
{
    SAFE_DELETE(m_pPlayer);
    SAFE_DELETE(m_pField);
    SAFE_DELETE(m_pLowLevelShop);
    SAFE_DELETE(m_pMidLevelShop);
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
                m_pLowLevelShop->Update();
            }
            break;
        case 2:
            if (m_pMidLevelShop)
            {
                m_pMidLevelShop->Update();
            }
            break;
        case 3:
            if (m_pHighLevelShop)
            {
                m_pHighLevelShop->Update();
            }
            break;
        case 4:
            return;
        }
    }
}

