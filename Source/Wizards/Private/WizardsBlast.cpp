// Fill out your copyright notice in the Description page of Project Settings.

#include "Wizards.h"
#include "WizardsBlast.h"


// Sets default values
AWizardsBlast::AWizardsBlast()
{
	bReplicates = true;
	this->bCollideWhenPlacing = false;
	//this->NotifyActorBeginOverlap;
	this->SetActorEnableCollision(false);
	PrimaryActorTick.bCanEverTick = true;
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName(TEXT("OverlapAll"));
	//CollisionComp->OnComponentHit.AddDynamic(this, &AWizardsBlast::OnHit);
	RootComponent = CollisionComp;
	InitialLifeSpan = 0.3f;
	MyParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Madness"));
	//ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName6(TEXT("ParticleSystem'/Game/FirstPerson/Particles/P_Fire_Blast.P_Fire_Blast'"));
	//MyParticleSystem->SetTemplate(ArbitraryParticleName6.Object);
}

/*void AWizardsBlast::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {

}*/

void AWizardsBlast::SpellCreation(UParticleSystem* theParticle, float blastSize, float blastDamage, AWizardsCharacter* theWiz) {
	if (theParticle == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("The gods have forsaken us!"));
	}
	MyParticleSystem->SetTemplate(theParticle);
	MyParticleSystem->AttachTo(RootComponent);
	MyParticleSystem->SetWorldScale3D(FVector(blastSize));
	CollisionComp->SetSphereRadius(blastSize);
	owningWizard = theWiz;
	//UE_LOG(LogTemp, Warning, TEXT("I can't believe it's not null!"));
	//CollisionComp->SetSphereRadius(20.f);
	//MyParticleSystem->Template = ArbitraryParticleName.Object;
	//MyParticleSystem->bAutoActivate = true;
	//MyParticleSystem->SetHiddenInGame(false);
}