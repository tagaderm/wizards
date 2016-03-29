// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "WizardsCharacter.h"
#include "WizardsHUD.generated.h"


UCLASS()
class AWizardsHUD : public AHUD
{
	GENERATED_BODY()

public:
	AWizardsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	UPROPERTY()
	UFont* HUDFont;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	
	AWizardsCharacter* TheWizard;

};

