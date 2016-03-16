// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CustomSpellFunctions.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDS_API UCustomSpellFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "VictoryBPLibrary")
	static int32 MostDefinitelyaTest();
	
	
	
};
