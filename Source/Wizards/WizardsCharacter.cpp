// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Wizards.h"
#include "WizardsCharacter.h"
#include "WizardsProjectile.h"
#include "WizardsBlast.h"
#include "WizardsCone.h"
#include "WizardsSaveGame.h"
#include "UnrealNetwork.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"

//DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AWizardsCharacter

AWizardsCharacter::AWizardsCharacter()
{
	bReplicates = true;
	//Tick for mana regen
	PrimaryActorTick.bCanEverTick = true;
	//Set Health and Mana
	Health = 100.0;
	maxHealth = 100.0;
	Mana = 100.0;
	maxMana = 100.0;
	//Spell Stuff for Testing
	//SList.spellCost = 10.0;

	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	//SList.myParticle = ArbitraryParticleName.Object;
	//SList.test = &ArbitraryParticleName;
	currSpell = 0;
	//For the record, this probably isn't the best way to get particles for the spells but it works
	//A better method, implemented at a later and unknown date, would be to hold this array in its own class
	//that is called once and never destroyed
	//Projectiles
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName0(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Fire_Projectile.P_Fire_Projectile'"));
	particleList.Add(ArbitraryParticleName0.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName1(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Lightning_Projectile.P_Lightning_Projectile'"));
	particleList.Add(ArbitraryParticleName1.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName2(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Water_Projectile.P_Water_Projectile'"));
	particleList.Add(ArbitraryParticleName2.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName3(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Ice_Projectile.P_Ice_Projectile'"));
	particleList.Add(ArbitraryParticleName3.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName4(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Earth_Projectile.P_Earth_Projectile'"));
	particleList.Add(ArbitraryParticleName4.Object);
	//Now for all of the EXPLOSIONS
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName5(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Fire_Blast.P_Fire_Blast'"));
	particleList.Add(ArbitraryParticleName5.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName6(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Lightning_Blast.P_Lightning_Blast'"));
	particleList.Add(ArbitraryParticleName6.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName7(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Water_Blast.P_Water_Blast'"));
	particleList.Add(ArbitraryParticleName7.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName8(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Ice_Blast.P_Ice_Blast'"));
	particleList.Add(ArbitraryParticleName8.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName9(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Earth_Blast.P_Earth_Blast'"));
	particleList.Add(ArbitraryParticleName9.Object);
	//Next up is cones
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName10(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Fire_Cone.P_Fire_Cone'"));
	particleList.Add(ArbitraryParticleName10.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName11(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Lightning_Cone.P_Lightning_Cone'"));
	particleList.Add(ArbitraryParticleName11.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName12(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Water_Cone.P_Water_Cone'"));
	particleList.Add(ArbitraryParticleName12.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName13(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Ice_Cone.P_Ice_Cone'"));
	particleList.Add(ArbitraryParticleName13.Object);
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName14(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Earth_Cone.P_Earth_Cone'"));
	particleList.Add(ArbitraryParticleName14.Object);


	//spell test;
	//SList.Add(test);
	//SList[currSpell].spellCost = 10.0;
	//SList[currSpell].theWizard = this;
	//SList[currSpell].canBounce = true;
	//ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName8(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	//SList[currSpell].myParticle = ArbitraryParticleName8.Object;
	//SList.test = &ArbitraryParticleName;
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


void AWizardsCharacter::newCharactersSpells()
{
	UWizardsSaveGame* LoadGameInstance = NewObject<UWizardsSaveGame>();
	//	spellList = LoadGameInstance->spellList;
	//if is empty
	if (LoadGameInstance->LoadGameDataFromFile()) {

		for (int i = 0; i < 5; i++) {
			FtheSpell thisSpell;
			mySpellBook.Add(thisSpell);
			mySpellBook[i].spellEffect = LoadGameInstance->spellBook[i]->spellEffect;
			mySpellBook[i].spellType = LoadGameInstance->spellBook[i]->spellType;
			mySpellBook[i].spellCost = LoadGameInstance->spellBook[i]->spellCost;
			mySpellBook[i].spellSpeed = LoadGameInstance->spellBook[i]->spellSpeed*9000.0 + 1000.0;//range from 1000 to 10000
			mySpellBook[i].spellDamage = LoadGameInstance->spellBook[i]->spellDamage;//not in at the moment
			mySpellBook[i].spellRange = LoadGameInstance->spellBook[i]->spellRange*4.0 + 1.0; //1 to 5 seconds
			mySpellBook[i].spellSize = LoadGameInstance->spellBook[i]->spellSize*4.0 + 1.0;//range 1 to 5
			mySpellBook[i].canBounce = LoadGameInstance->spellBook[i]->canBounce;//boolean, in
			mySpellBook[i].hasGravity = LoadGameInstance->spellBook[i]->hasGravity;//totally in
			mySpellBook[i].isHoming = LoadGameInstance->spellBook[i]->isHoming; //not currenttly implemented
			mySpellBook[i].explodeOnCollision = LoadGameInstance->spellBook[i]->explodeOnCollision; //none of this shit down here is implemented
			mySpellBook[i].explodeOnDeath = LoadGameInstance->spellBook[i]->explodeOnDeath;
			mySpellBook[i].explosionHitDamage = LoadGameInstance->spellBook[i]->explosionHitDamage;
			mySpellBook[i].explosionHitSize = LoadGameInstance->spellBook[i]->explosionHitSize*3.0 + 2.0;
			mySpellBook[i].explosionDeathDamage = LoadGameInstance->spellBook[i]->explosionDeathDamage;
			mySpellBook[i].explosionDeathSize = LoadGameInstance->spellBook[i]->explosionDeathSize*3.0 + 2.0;
			//mySpellBook[i]->myParticle = particleList[mySpellBook[i]->spellEffect + mySpellBook[i]->spellType * 5];
			//mySpellBook[i]->explParticle = particleList[mySpellBook[i]->spellEffect + 5];
			UE_LOG(LogTemp, Warning, TEXT("Spell Gathering Succesful!"));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Abort Mission!"));
	}
}

/////////////
// On Tick
void AWizardsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Mana <= maxMana) {
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
	InputComponent->BindAction("ChangeSpell1", IE_Pressed, this, &AWizardsCharacter::spellSwitch<0>);
	InputComponent->BindAction("ChangeSpell2", IE_Pressed, this, &AWizardsCharacter::spellSwitch<1>);
	InputComponent->BindAction("ChangeSpell3", IE_Pressed, this, &AWizardsCharacter::spellSwitch<2>);
	InputComponent->BindAction("ChangeSpell4", IE_Pressed, this, &AWizardsCharacter::spellSwitch<3>);
	InputComponent->BindAction("ChangeSpell5", IE_Pressed, this, &AWizardsCharacter::spellSwitch<4>);




	//InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AWizardsCharacter::TouchStarted);
	if (EnableTouchscreenMovement(InputComponent) == false)
	{
		InputComponent->BindAction("Fire", IE_Pressed, this, &AWizardsCharacter::OnFire);
		InputComponent->BindAction("Fire", IE_Released, this, &AWizardsCharacter::OffFire);

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
	if (!mySpellBook.IsValidIndex(0)) {
		UE_LOG(LogTemp, Warning, TEXT("Spell Gathering Needed!"));
		newCharactersSpells();
	}
	if (Mana > mySpellBook[currSpell].spellCost) {
		Mana -= mySpellBook[currSpell].spellCost;
		// try and fire a projectile

		if (mySpellBook[currSpell].spellType == 0)
		{
			const FRotator SpawnRotation = GetControlRotation();
			const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World)
			{
				// spawn the projectile at the muzzle
				/*UParticleSystem* projParticle = particleList[mySpellBook[currSpell].spellEffect + mySpellBook[currSpell].spellType * 5];
				UParticleSystem* blastParticle = particleList[mySpellBook[currSpell].spellEffect + 5];
				AWizardsProjectile* wizardsSpell = World->SpawnActor<AWizardsProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);// , myparams);
				wizardsSpell->SpellCreation(&mySpellBook[currSpell], projParticle, blastParticle, this);*/
				if (Role < ROLE_Authority)
				{
					ServerFireProjectile(mySpellBook[currSpell], SpawnRotation, SpawnLocation);//mySpellBook[currSpell]);
				}
				else {
					ClientFireProjectile(mySpellBook[currSpell], SpawnRotation, SpawnLocation);
				}
			}
		}
		else if (mySpellBook[currSpell].spellType == 1) {
			const FRotator SpawnRotation = FRotator(0.0);//GetControlRotation();
														 // MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = FVector(0.0);//GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World)
			{
				// spawn the projectile at the muzzle
				/*UParticleSystem* blastParticle = particleList[mySpellBook[currSpell].spellEffect + mySpellBook[currSpell].spellType * 5];
				AWizardsBlast* wizardsSpell = World->SpawnActor<AWizardsBlast>(BlastClass, SpawnLocation, SpawnRotation);// , myparams);
				wizardsSpell->SpellCreation(blastParticle, mySpellBook[currSpell].spellSize, mySpellBook[currSpell].spellDamage, this);
				wizardsSpell->AttachRootComponentTo(GetCapsuleComponent());//Probably useful for Blasts, Rays, and Conical attacks*/
				if (Role < ROLE_Authority)
				{
					ServerFireProjectile(mySpellBook[currSpell], SpawnRotation, SpawnLocation);
				}
				else {
					ClientFireProjectile(mySpellBook[currSpell], SpawnRotation, SpawnLocation);
				}
			}
		}
		else if (mySpellBook[currSpell].spellType == 2) {
			const FRotator SpawnRotation = FRotator(0.0);//GetControlRotation();
														 // MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = FVector(0.0);//GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World)
			{
				// spawn the projectile at the muzzle
				/*UParticleSystem* coneParticle = particleList[mySpellBook[currSpell].spellEffect + mySpellBook[currSpell].spellType * 5];
				AWizardsCone* wizardsCone = World->SpawnActor<AWizardsCone>(ConeClass, SpawnLocation, SpawnRotation);// , myparams);
				wizardsCone->SpellCreation(coneParticle, mySpellBook[currSpell].spellSize, mySpellBook[currSpell].spellDamage, this);
				wizardsCone->AttachRootComponentTo(GetCapsuleComponent());//Probably useful for Blasts, Rays, and Conical attacks
				activeAttack = Cast<AActor>(wizardsCone);*/
				if (Role < ROLE_Authority)
				{
					ServerFireProjectile(mySpellBook[currSpell], SpawnRotation, SpawnLocation);
				}
				else {
					ClientFireProjectile(mySpellBook[currSpell], SpawnRotation, SpawnLocation);
				}
			}
		}
		// God this sound is so annoying
		/*if (FireSound != NULL)
		{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
		}*/

		// try and play a firing animation if specified
		if (FireAnimation != NULL)
		{
			// Get the animation object for the arms mesh
			UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
			if (AnimInstance != NULL)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.f);
			}
		}

	}
}

void AWizardsCharacter::OffFire() {
	if (activeAttack != NULL) {
		activeAttack->Destroy();
	}
}


void AWizardsCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == true)
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
	if ((FingerIndex == TouchItem.FingerIndex) && (TouchItem.bMoved == false))
	{
		OnFire();
	}
	TouchItem.bIsPressed = false;
}

void AWizardsCharacter::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if ((TouchItem.bIsPressed == true) && (TouchItem.FingerIndex == FingerIndex))
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
					FVector2D ScaledDelta = FVector2D(MoveDelta.X, MoveDelta.Y) / ScreenSize;
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
	if (FPlatformMisc::GetUseVirtualJoysticks() || GetDefault<UInputSettings>()->bUseMouseForTouch)
	{
		bResult = true;
		InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AWizardsCharacter::BeginTouch);
		InputComponent->BindTouch(EInputEvent::IE_Released, this, &AWizardsCharacter::EndTouch);
		InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AWizardsCharacter::TouchUpdate);
	}
	return bResult;
}


template<int newspell>
void AWizardsCharacter::spellSwitch()
{
	currSpell = newspell;
}


float AWizardsCharacter::GetHealth() {
	return Health;
}
float AWizardsCharacter::GetMana() {
	return Mana;
}

void AWizardsCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWizardsCharacter, mySpellBook);
	DOREPLIFETIME(AWizardsCharacter, Mana);
	DOREPLIFETIME(AWizardsCharacter, currSpell);
}

void AWizardsCharacter::ServerFireProjectile_Implementation(FtheSpell castSpell, FRotator rotation, FVector location) {
	//UWorld* const World = GetWorld();
	UE_LOG(LogTemp, Warning, TEXT("Server Side"));
	//OnFire();
	ClientFireProjectile(castSpell, rotation, location);
	/*if (theSpell->spellType == 0) {
		const FRotator SpawnRotation = GetControlRotation();
		const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);
		AWizardsProjectile* wizardsSpell = World->SpawnActor<AWizardsProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);// , myparams);
		wizardsSpell->SpellCreation(theSpell, this);

	}
	else if (theSpell->spellType == 1) {
		const FRotator SpawnRotation = FRotator(0.0);//GetControlRotation();
		const FVector SpawnLocation = FVector(0.0);//GetActorLocation() + SpawnRotation.RotateVector(GunOffset);
		AWizardsBlast* wizardsSpell = World->SpawnActor<AWizardsBlast>(BlastClass, SpawnLocation, SpawnRotation);// , myparams);
		wizardsSpell->SpellCreation(theSpell->myParticle, theSpell->spellSize, theSpell->spellDamage, this);
		wizardsSpell->AttachRootComponentTo(GetCapsuleComponent());//Probably useful for Blasts, Rays, and Conical attacks
		UE_LOG(LogTemp, Warning, TEXT("Boom!"));
	}
	else if (theSpell->spellType == 2) {
		const FRotator SpawnRotation = FRotator(0.0);//GetControlRotation();
		const FVector SpawnLocation = FVector(0.0);//GetActorLocation() + SpawnRotation.RotateVector(GunOffset);
		AWizardsCone* wizardsCone = World->SpawnActor<AWizardsCone>(ConeClass, SpawnLocation, SpawnRotation);// , myparams);
		wizardsCone->SpellCreation(theSpell->myParticle, theSpell->spellSize, theSpell->spellDamage, this);
		wizardsCone->AttachRootComponentTo(GetCapsuleComponent());//Probably useful for Blasts, Rays, and Conical attacks
		activeAttack = Cast<AActor>(wizardsCone);
		UE_LOG(LogTemp, Warning, TEXT("Svoosh!"));
	}*/
}
bool AWizardsCharacter::ServerFireProjectile_Validate(FtheSpell castSpell, FRotator rotation, FVector location) {
	return true;
}

void AWizardsCharacter::ClientFireProjectile_Implementation(FtheSpell castSpell, FRotator rotation, FVector location){
	/*if (!mySpellBook.IsValidIndex(0)) {
		UE_LOG(LogTemp, Warning, TEXT("Spell Gathering Needed!"));
		newCharactersSpells();
	}*/
	
	//UE_LOG(LogTemp, Warning, TEXT("Role %d has currSpell %d and SpawnRotation "), Role, currSpell);

	if (castSpell.spellType == 0)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			// spawn the projectile at the muzzle
			UParticleSystem* projParticle = particleList[castSpell.spellEffect + castSpell.spellType * 5];
			UParticleSystem* blastParticle = particleList[castSpell.spellEffect + 5];
			AWizardsProjectile* wizardsSpell = World->SpawnActor<AWizardsProjectile>(ProjectileClass, location, rotation);// , myparams);
			wizardsSpell->SpellCreation(&castSpell, projParticle, blastParticle, this);
		}
	}
	else if (castSpell.spellType == 1) {
		UWorld* const World = GetWorld();
		if (World)
		{
			// spawn the projectile at the muzzle
			UParticleSystem* blastParticle = particleList[castSpell.spellEffect + castSpell.spellType * 5];
			AWizardsBlast* wizardsSpell = World->SpawnActor<AWizardsBlast>(BlastClass, location, rotation);// , myparams);
			wizardsSpell->SpellCreation(blastParticle, castSpell.spellSize, castSpell.spellDamage, this);
			wizardsSpell->AttachRootComponentTo(GetCapsuleComponent());//Probably useful for Blasts, Rays, and Conical attacks
		}
	}
	else if (castSpell.spellType == 2) {
		UWorld* const World = GetWorld();
		if (World)
		{
			// spawn the projectile at the muzzle
			UParticleSystem* coneParticle = particleList[castSpell.spellEffect + castSpell.spellType * 5];
			AWizardsCone* wizardsCone = World->SpawnActor<AWizardsCone>(ConeClass, location, rotation);// , myparams);
			wizardsCone->SpellCreation(coneParticle, castSpell.spellSize, castSpell.spellDamage, this);
			wizardsCone->AttachRootComponentTo(GetCapsuleComponent());//Probably useful for Blasts, Rays, and Conical attacks
			activeAttack = Cast<AActor>(wizardsCone);
		}
	}
}	
bool AWizardsCharacter::ClientFireProjectile_Validate(FtheSpell castSpell, FRotator rotation, FVector location){
	return true;	
}
