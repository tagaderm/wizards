// Fill out your copyright notice in the Description page of Project Settings.

#include "Wizards.h"
#include "WizardsSaveGame.h"

UWizardsSaveGame::UWizardsSaveGame()
{
	SaveSlotName = TEXT("TestSaveSlot");
	gameSaved = false;
	UserIndex = 0;
}


