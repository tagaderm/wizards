// Fill out your copyright notice in the Description page of Project Settings.

#include "Wizards.h"
#include "WizardsGameInstance.h"
#include "Online.h"
//#include "Networking.h"
#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"


void UWizardsGameInstance::Init()
{
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		IOnlineSessionPtr SessionInt = OnlineSub->GetSessionInterface();
		if (SessionInt.IsValid())
		{
			int32 ControllerId = 0;
			if (ControllerId != 255)
			{
				FOnSessionUserInviteAcceptedDelegate inviteDelegate = FOnSessionUserInviteAcceptedDelegate::CreateUObject(this, &UWizardsGameInstance::OnSessionUserInviteAccepted);
				SessionInt->AddOnSessionUserInviteAcceptedDelegate_Handle(inviteDelegate);

				FOnJoinSessionCompleteDelegate joinDelegate = FOnJoinSessionCompleteDelegate::CreateUObject(this, &UWizardsGameInstance::OnJoinSessionCompleted);
				SessionInt->AddOnJoinSessionCompleteDelegate_Handle(joinDelegate);
			}
		}
	}
}

void UWizardsGameInstance::OnSessionUserInviteAccepted(bool bWasSuccessful, int32 LocalUserNum, TSharedPtr<const FUniqueNetId>, const FOnlineSessionSearchResult& SearchResult)
{
	//UE_LOG(DSS_STEAM, Verbose, TEXT("OnSessionInviteAccepted LocalUserNum: %d bSuccess: %d"), LocalUserNum, bWasSuccessful);

	if (bWasSuccessful)
	{
		if (SearchResult.IsValid())
		{
			IOnlineSessionPtr SessionInt = IOnlineSubsystem::Get()->GetSessionInterface();
			SessionInt->JoinSession(LocalUserNum, GameSessionName, SearchResult);
		}
		else
		{
			//UE_LOG(DSS_STEAM, Warning, TEXT("Invite accept returned no search result."));
		}
	}
}

void UWizardsGameInstance::OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	//UE_LOG(DSS_STEAM, Verbose, TEXT("JoinSessionCompleted"));
	IOnlineSessionPtr Sessions = IOnlineSubsystem::Get()->GetSessionInterface();
	if (Sessions.IsValid())
	{
		//UE_LOG(DSS_STEAM, Verbose, TEXT("Sessions Valid"));
		if (Result == EOnJoinSessionCompleteResult::Success)
		{
			// Client travel to the server
			FString ConnectString;
			if (Sessions->GetResolvedConnectString(GameSessionName, ConnectString))
			{
				//UE_LOG(DSS_STEAM, Log, TEXT("Join session: traveling to %s"), *ConnectString);
				GetFirstLocalPlayerController()->ClientTravel(ConnectString, TRAVEL_Absolute);
			}
		}
	}
}


