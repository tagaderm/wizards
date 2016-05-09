// Fill out your copyright notice in the Description page of Project Settings.

#include "Wizards.h"
#include "spellBook.h"
#include "UnrealNetwork.h"

UspellBook::UspellBook() {
	//bReplicates = true;
}
//this may be unneccessary and has no effect on the current bug
void UspellBook::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	DOREPLIFETIME(UspellBook, myParticle);
	DOREPLIFETIME(UspellBook, explParticle);
	DOREPLIFETIME(UspellBook, spellEffect);
	DOREPLIFETIME(UspellBook, spellType);
	DOREPLIFETIME(UspellBook, spellCost);
	DOREPLIFETIME(UspellBook, spellSpeed);
	DOREPLIFETIME(UspellBook, spellDamage);
	DOREPLIFETIME(UspellBook, spellRange); //lifetime for projectiles, distance for rays and blasts
	DOREPLIFETIME(UspellBook, spellSize);
	DOREPLIFETIME(UspellBook, canBounce);
	DOREPLIFETIME(UspellBook, hasGravity);
	DOREPLIFETIME(UspellBook, isHoming);
	DOREPLIFETIME(UspellBook, explodeOnCollision);
	DOREPLIFETIME(UspellBook, explodeOnDeath);
	DOREPLIFETIME(UspellBook, explosionHitDamage);
	DOREPLIFETIME(UspellBook, explosionHitSize);
	DOREPLIFETIME(UspellBook, explosionDeathDamage);
	DOREPLIFETIME(UspellBook, explosionDeathSize);
}
