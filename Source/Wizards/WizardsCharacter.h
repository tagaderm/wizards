// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "ParticleDefinitions.h"
#include "spellBook.h"
#include "WizardsCharacter.generated.h"

class UInputComponent;

UCLASS(config=Game)
class AWizardsCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;
public:
	AWizardsCharacter();

	UFUNCTION(BlueprintCallable, Category = "CharacterFunctions")
	void newCharactersSpells();

	void Tick(float DeltaTime) override;	

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	/** Health */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay)
	float Health;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay)
	float maxHealth;

	/** Mana */
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay)
	float Mana;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay)
	float maxMana;
	UPROPERTY()
	UspellBook* thisSpell;
	UPROPERTY()
	TArray<UspellBook*> mySpellBook;
	TArray<UParticleSystem*> particleList;
	struct spell {
		UParticleSystem* myParticle;
		int8 spellType;
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
	};
	TArray<spell> SList;
	int8 currSpell;

	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, Category=Projectile)
	TSubclassOf<class AWizardsProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

protected:
	
	/** Fires a projectile. */
	void OnFire();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	struct TouchData
	{
		TouchData() { bIsPressed = false;Location=FVector::ZeroVector;}
		bool bIsPressed;
		ETouchIndex::Type FingerIndex;
		FVector Location;
		bool bMoved;
	};
	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
	TouchData	TouchItem;
	
	//Called when you switch a spell
	template<int newspell>
	void spellSwitch();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	/* 
	 * Configures input for touchscreen devices if there is a valid touch interface for doing so 
	 *
	 * @param	InputComponent	The input component pointer to bind controls to
	 * @returns true if touch controls were enabled.
	 */
	bool EnableTouchscreenMovement(UInputComponent* InputComponent);

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	float GetHealth();
	float GetMana();

};

