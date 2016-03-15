// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Wizards.h"
#include "WizardsCharacter.h"
#include "WizardsProjectile.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"

//DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AWizardsCharacter

AWizardsCharacter::AWizardsCharacter()
{ 
	//Tick for mana regen
	PrimaryActorTick.bCanEverTick = true;
	//Set Health and Mana
	Health = 100.0;
	maxHealth = 100.0;
	Mana = 100.0;
	maxMana = 100.0;
	//Spell Stuff for Testing
	SList.spellCost = 10.0;

	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	SList.myParticle = ArbitraryParticleName.Object;
	SList.test = &ArbitraryParticleName;
	//SList.particleLocation = FName(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	Mesh1P->AttachParent = FirstPersonCameraComponent;
	Mesh1P->RelativeLocation = FVector(0.f, 0.f, -150.f);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

/////////////
// On Tick
void AWizardsCharacter::Tick(float DeltaTime)  
{  
    Super::Tick(DeltaTime);
    if(Mana <= maxMana){
	Mana += DeltaTime;
    }
}

//////////////////////////////////////////////////////////////////////////
// Input

void AWizardsCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
	//InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AWizardsCharacter::TouchStarted);
	if( EnableTouchscreenMovement(InputComponent) == false )
	{
		InputComponent->BindAction("Fire", IE_Pressed, this, &AWizardsCharacter::OnFire);
	}
	
	InputComponent->BindAxis("MoveForward", this, &AWizardsCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AWizardsCharacter::MoveRight);
	
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AWizardsCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AWizardsCharacter::LookUpAtRate);
}

void AWizardsCharacter::OnFire()
{ 
	if(Mana > SList.spellCost){
		Mana -= SList.spellCost;
		// try and fire a projectile
		if (ProjectileClass != NULL)
		{
			const FRotator SpawnRotation = GetControlRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World)
			{
				// spawn the projectile at the muzzle
				FActorSpawnParameters myparams;
				myparams.Owner = Cast<AActor>(this);
				myparams.Instigator = Cast<APawn>(this);
				myparams.bAllowDuringConstructionScript = false;
				myparams.bNoFail = true;
				myparams.bRemoteOwned = false;
				//AWizardsProjectile* wizardsSpell = 
				AWizardsProjectile* wizardsSpell = World->SpawnActor<AWizardsProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);// , myparams);
				wizardsSpell->SpellCreation(&SList);
				 
			}
		}

		// try and play the sound if specified
		if (FireSound != NULL)
		{
			UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}

		// try and play a firing animation if specified
		if(FireAnimation != NULL)
		{
			// Get the animation object for the arms mesh
			UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
			if(AnimInstance != NULL)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.f);
			}
		}
	}

}

void AWizardsCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if( TouchItem.bIsPressed == true )
	{
		return;
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void AWizardsCharacter::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == false)
	{
		return;
	}
	if( ( FingerIndex == TouchItem.FingerIndex ) && (TouchItem.bMoved == false) )
	{
		OnFire();
	}
	TouchItem.bIsPressed = false;
}

void AWizardsCharacter::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if ((TouchItem.bIsPressed == true) && ( TouchItem.FingerIndex==FingerIndex))
	{
		if (TouchItem.bIsPressed)
		{
			if (GetWorld() != nullptr)
			{
				UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
				if (ViewportClient != nullptr)
				{
					FVector MoveDelta = Location - TouchItem.Location;
					FVector2D ScreenSize;
					ViewportClient->GetViewportSize(ScreenSize);
					FVector2D ScaledDelta = FVector2D( MoveDelta.X, MoveDelta.Y) / ScreenSize;									
					if (ScaledDelta.X != 0.0f)
					{
						TouchItem.bMoved = true;
						float Value = ScaledDelta.X * BaseTurnRate;
						AddControllerYawInput(Value);
					}
					if (ScaledDelta.Y != 0.0f)
					{
						TouchItem.bMoved = true;
						float Value = ScaledDelta.Y* BaseTurnRate;
						AddControllerPitchInput(Value);
					}
					TouchItem.Location = Location;
				}
				TouchItem.Location = Location;
			}
		}
	}
}

void AWizardsCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AWizardsCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AWizardsCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AWizardsCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool AWizardsCharacter::EnableTouchscreenMovement(class UInputComponent* InputComponent)
{
	bool bResult = false;
	if(FPlatformMisc::GetUseVirtualJoysticks() || GetDefault<UInputSettings>()->bUseMouseForTouch )
	{
		bResult = true;
		InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AWizardsCharacter::BeginTouch);
		InputComponent->BindTouch(EInputEvent::IE_Released, this, &AWizardsCharacter::EndTouch);
		InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AWizardsCharacter::TouchUpdate);
	}
	return bResult;
}

float AWizardsCharacter::GetHealth(){
	return Health;
}
float AWizardsCharacter::GetMana(){
	return Mana;
}
