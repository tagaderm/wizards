// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Actor.h"
#include "WizardsCharacter.h"
#include "WizardsBlast.h"
#include "spellBook.h"
#include "ParticleDefinitions.h"
#include "WizardsProjectile.generated.h"

UCLASS(config=Game)
class AWizardsProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	class USphereComponent* CollisionComp;
	class UParticleSystemComponent* MyParticleSystem;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement;
	AWizardsCharacter* owningWizard;

	bool shouldBounce;

public:
	AWizardsProjectile();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void SpellCreation(FtheSpell* theSpell, UParticleSystem* projPart, UParticleSystem* blastPart, AWizardsCharacter* theWiz);

	/** Returns CollisionComp subobject **/
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
	//UPROPERTY(EditAnywhere)
	UParticleSystem* blastParticle;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWizardsBlast> BlastClass;
	bool explodeDeath = false;
	bool explodeHit = false;
	float bBlastSize;
	float bBlastDamage;
	float dBlastSize;
	float dBlastDamage;
	int8 maxBlasts = 5;

	void LifeSpanExpired() override;

};

