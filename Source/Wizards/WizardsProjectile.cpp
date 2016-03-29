// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Wizards.h"
#include "WizardsProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

AWizardsProjectile::AWizardsProjectile()
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AWizardsProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 10000.f;
	ProjectileMovement->MaxSpeed = 10000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

  MyParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Madness"));
  //SetLifeSpan(30.f);
}

void AWizardsProjectile::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	}
  else if(shouldBounce == false && (OtherActor != this) && (OtherActor != owningWizard) && explodeDeath){
  	//UE_LOG(LogTemp, Warning, TEXT("Bounce!"));
    //ProjectileMovement->InitialSpeed = 0.f;
	ProjectileMovement->MaxSpeed = 0.01f;//need to look up how to just set speed to 0
  	ProjectileMovement->ProjectileGravityScale = 0.f;
	}
  else if ((OtherActor != this) && (OtherActor != owningWizard) && explodeHit && maxBlasts > 0) {
	  //const FRotator SpawnRotation = GetControlRotation();
	  // MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	  const FVector SpawnLocation = GetActorLocation();
	  const FRotator spawnRotation(0.0, 0.0, 0.0);
	  UWorld* const World = GetWorld();
	  if (World)
	  {
		  //BlastClass = NewObject<AWizardsBlast>();
		  AWizardsBlast* wizardsSpell = World->SpawnActor<AWizardsBlast>(BlastClass, SpawnLocation, spawnRotation);//, SpawnRotation);// , myparams);
		  wizardsSpell->SpellCreation(blastParticle, bBlastSize, bBlastDamage, owningWizard);
		  maxBlasts -= 1;

	  }
  }
  else if (maxBlasts == 0) {
	  if (explodeDeath) {
		  const FVector SpawnLocation = GetActorLocation();
		  const FRotator spawnRotation(0.0, 0.0, 0.0);
		  UWorld* const World = GetWorld();
		  if (World)
		  {
			  //BlastClass = NewObject<AWizardsBlast>();
			  AWizardsBlast* wizardsSpell = World->SpawnActor<AWizardsBlast>(BlastClass, SpawnLocation, spawnRotation);//, SpawnRotation);// , myparams);
			  wizardsSpell->SpellCreation(blastParticle, bBlastSize, bBlastDamage, owningWizard);
			  maxBlasts -= 1;

		  }
	  }
	  Destroy();
  }
}

void AWizardsProjectile::SpellCreation(UspellBook* theSpell, AWizardsCharacter* theWiz) {
	if(theSpell != NULL){
		MyParticleSystem->SetTemplate(theSpell->myParticle);
		MyParticleSystem->AttachTo(RootComponent);
		MyParticleSystem->SetWorldScale3D( FVector( theSpell->spellSize ) );
		shouldBounce = theSpell->canBounce;
		ProjectileMovement->bShouldBounce = theSpell->canBounce;
		owningWizard = theWiz;
		if (theSpell->hasGravity) {
			ProjectileMovement->ProjectileGravityScale = 1.0f;
		}
		ProjectileMovement->MaxSpeed = theSpell->spellSpeed;
		SetLifeSpan(theSpell->spellRange);
		bBlastSize = theSpell->explosionHitSize;
		bBlastDamage = theSpell->explosionHitDamage;
		blastParticle = theSpell->explParticle;
		explodeHit = theSpell->explodeOnCollision;
		explodeDeath = theSpell->explodeOnDeath;

		//UE_LOG(LogTemp, Warning, TEXT("I can't believe it's not null!"));
		//CollisionComp->SetSphereRadius(20.f);
		//MyParticleSystem->Template = ArbitraryParticleName.Object;
		//MyParticleSystem->bAutoActivate = true;
		//MyParticleSystem->SetHiddenInGame(false);
	}
}

void AWizardsProjectile::LifeSpanExpired() {
	if (explodeDeath) {
		const FVector SpawnLocation = GetActorLocation();
		const FRotator spawnRotation(0.0, 0.0, 0.0);
		UWorld* const World = GetWorld();
		if (World)
		{
			//BlastClass = NewObject<AWizardsBlast>();
			AWizardsBlast* wizardsSpell = World->SpawnActor<AWizardsBlast>(BlastClass, SpawnLocation, spawnRotation);//, SpawnRotation);// , myparams);
			wizardsSpell->SpellCreation(blastParticle, bBlastSize, bBlastDamage, owningWizard);
			maxBlasts -= 1;

		}
		Super::LifeSpanExpired();
	}
}