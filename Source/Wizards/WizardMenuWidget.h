// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "WizardsCharacter.h"
#include "WizardsSaveGame.h"
#include "ParticleDefinitions.h"
#include "WizardMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDS_API UWizardMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	void UWizardsMenuWidget();

	//Initialize with previous values or defaults if nothing present
	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void spellsInitialize();

	//Saves the spells
	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void spellsSave();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setEffect(int32 effectChange);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setType(int32 effectChange);

	//Called when spell is changed in spell bar
	//Changes all values to this spells values
	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void spellChange(int32 spellSlot);

	//List of all setters
	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setGravity(bool hasGravity);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setBounce(bool hasBounce);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setHoming(bool isHoming);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setExplodeHit(bool explodeHit);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setExplodeDeath(bool explodeDeath);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setSpeed(float speed);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setRange(float life);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setSize(float size);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setCost(float cost);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setExplHitDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setExplHitSize(float size);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setExplDeathDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	void setExplDeathSize(float size);



	//List of all getters

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	FName getEffect();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	FName getType();


	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	bool getGravity();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	bool getBounce();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	bool getHoming();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	bool getExplodeHit();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	bool getExplodeDeath();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	float getDamage();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	float getSpeed();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	float getRange();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	float getSize();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	float getCost();
	
	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	float getExplHitDamage();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	float getExplHitSize();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	float getExplDeathDamage();

	UFUNCTION(BlueprintCallable, Category = "CustomSpells")
	float getExplDeathSize();

	//The Spell Array that gets Loaded/Saved and is called by character
	int32 currSpell = 0;
	UPROPERTY()
	TArray<UspellBook*> spellList;
	UParticleSystem* theParticle;


	
	
	
};
