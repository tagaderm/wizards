// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "WizardsCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "WizardsSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDS_API UWizardsSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;
	
	//UPROPERTY(VisibleAnywhere, Category = Basic)
	TArray<AWizardsCharacter::spell> spellList;
	bool gameSaved;
	uint32 UserIndex;
	UWizardsSaveGame();



};
