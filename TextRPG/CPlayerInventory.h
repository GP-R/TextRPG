#pragma once

#include "CItemContainer.h"

class CPlayerInventory : public CItemContainer
{
public:
	CPlayerInventory();
	CPlayerInventory(int iMaxSlotCount);
	virtual ~CPlayerInventory();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

public:
	virtual void Render() override;
};

