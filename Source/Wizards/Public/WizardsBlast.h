// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "WizardsCharacter.h"
//#include "spellBook.h"
#include "ParticleDefinitions.h"
#include "WizardsBlast.generated.h"

UCLASS(config = Game)
class WIZARDS_API AWizardsBlast : public AActor
{
	GENERATED_BODY()
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	class USphereComponent* CollisionComp;
	class UParticleSystemComponent* MyParticleSystem;

	AWizardsCharacter* owningWizard;

public:	
	// Sets default values for this actor's properties
	AWizardsBlast();

	//UFUNCTION()
	//void OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;
	void SpellCreation(UParticleSystem* theParticle, float blastSize, float blastDamage, AWizardsCharacter* theWiz);
	/** Returns CollisionComp subobject **/
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }

	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;

	
	
};
