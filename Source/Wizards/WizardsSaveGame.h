// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "WizardsCharacter.h"
#include "spellBook.h"
#include "Archive.h"
#include "ArchiveBase.h"
#include "FileManager.h"
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

	UWizardsSaveGame();

	TArray<UspellBook*> spellBook;
	FString ThePath;
	void SaveLoadData(FArchive& Ar, TArray<UspellBook*>& spellBook);
	bool SaveGameDataToFile();
	bool LoadGameDataFromFile();

};
