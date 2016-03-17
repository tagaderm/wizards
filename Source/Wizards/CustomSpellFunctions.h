// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "WizardsCharacter.h"
#include "CustomSpellFunctions.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDS_API UCustomSpellFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static int32 MostDefinitelyaTest();

	//Initialize with previous values or defaults if nothing present
	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void spellsInitialize();
	
	//Saves the spells
	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void spellsSave();
	
	//Called when spell is changed in spell bar
	//Changes all values to this spells values
	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void spellChange(int32 spellSlot);

	//List of all setters
	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setGravity(bool hasGravity);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setBounce(bool hasBounce);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setHoming(bool isHoming);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setExplodeHit(bool explodeHit);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setExplodeDeath(bool explodeDeath);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setSpeed(float speed);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setRange(float life);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setSize(float size);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setCost(float cost);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setExplHitDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setExplHitSize(float size);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setExplDeathDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static void setExplDeathSize(float size);



	//List of all getters

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static bool getGravity();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static bool getBounce();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static bool getHoming();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static bool getExplodeHit();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static bool getExplodeDeath();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static float getDamage();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static float getSpeed();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static float getRange();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static float getSize();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static float getCost();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static float getExplHitDamage();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static float getExplHitSize();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static float getExplDeathDamage();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	static float getExplDeathSize();
	
	//The Spell Array that gets Loaded/Saved and is called by character
	int32 currSpell;
	TArray<spell> spellList; 
	
	
};
