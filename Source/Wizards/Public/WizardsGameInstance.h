// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "OnlineSessionInterface.h"
//#include "OnlineSubsystemPackage.h"
#include "WizardsGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class WIZARDS_API UWizardsGameInstance : public UGameInstance
{
	GENERATED_BODY()

	virtual void Init() override;

	void OnSessionUserInviteAccepted(bool bWasSuccessful, int32 LocalUserNum, TSharedPtr<const FUniqueNetId>, const FOnlineSessionSearchResult& SearchResult);

	void OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	
	
};
