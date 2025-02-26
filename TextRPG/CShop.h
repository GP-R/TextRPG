#pragma once

#include <vector>

class CShop
{
public:
	CShop();
	CShop(const char* pName, vector<class CItem*>* vItems);
	virtual ~CShop();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Release();

public:

private:
	char m_sName[32];
	vector<class CItem*> m_vItemContainer;
};

