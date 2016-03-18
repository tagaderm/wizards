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
	ProjectileMovement->InitialSpeed = 7000.f;
	ProjectileMovement->MaxSpeed = 7000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->ProjectileGravityScale = 1.0f;

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
  else if(shouldBounce == false && (OtherActor != this) && (OtherActor != owningWizard)){
  	//UE_LOG(LogTemp, Warning, TEXT("Bounce!"));
    //ProjectileMovement->InitialSpeed = 0.f;
		ProjectileMovement->MaxSpeed = 0.01f;//need to look up how to just set speed to 0
  	ProjectileMovement->ProjectileGravityScale = 0.f;
	}
}

void AWizardsProjectile::SpellCreation(AWizardsCharacter::spell* theSpell, AWizardsCharacter* theWiz) {
	if(theSpell != NULL){
		MyParticleSystem->SetTemplate(theSpell->myParticle);
		MyParticleSystem->AttachTo(RootComponent);
		MyParticleSystem->SetWorldScale3D( FVector( 10 ) );
		owningWizard = theSpell->theWiz;
  	shouldBounce = theSpell->canBounce;

		//UE_LOG(LogTemp, Warning, TEXT("I can't believe it's not null!"));
		//CollisionComp->SetSphereRadius(20.f);
		//MyParticleSystem->Template = ArbitraryParticleName.Object;
		//MyParticleSystem->bAutoActivate = true;
		//MyParticleSystem->SetHiddenInGame(false);
	}
}
