// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "ParticleDefinitions.h"
#include "spellBook.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDS_API UspellBook : public UObject
{
	GENERATED_BODY()
public:
	UspellBook();
	UParticleSystem* myParticle;
	UParticleSystem* explParticle;
	uint8 spellEffect;
	uint8 spellType;
	float spellCost;
	float spellSpeed;
	float spellDamage;
	float spellRange; //lifetime for projectiles, distance for rays and blasts
	float spellSize;
	bool canBounce;
	bool hasGravity;
	bool isHoming;
	bool explodeOnCollision;
	bool explodeOnDeath;
	float explosionHitDamage;
	float explosionHitSize;
	float explosionDeathDamage;
	float explosionDeathSize;

	//bool IsNameStableForNetworking() const override;
	//Might not be necessary
	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const override;

	bool IsSupportedForNetworking() const override
	{
		return true;
	};

};

