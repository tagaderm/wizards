// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "WizardSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDS_API UWizardSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, Category = Experience)
	float currentExp;

	UPROPERTY(VisibleAnywhere, Category = Experience)
	int32 level;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;

	UWizardSaveGame();
};
