// Fill out your copyright notice in the Description page of Project Settings.

#include "Wizards.h"
#include "spellBook.h"
#include "WizardMenuWidget.h"


void UWizardMenuWidget::UWizardsMenuWidget() {
	ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	theParticle = ArbitraryParticleName.Object;
}

//Initialize with previous values or defaults if nothing present
void UWizardMenuWidget::spellsInitialize() {
	UWizardsSaveGame* LoadGameInstance = NewObject<UWizardsSaveGame>();
	//	spellList = LoadGameInstance->spellList;
	//if is empty
	if (!LoadGameInstance->LoadGameDataFromFile()) {
		//Initialize five spells
		//theSpell.myParticle = ArbitraryParticleName.Object;
		for (int i = 0; i < 5; i++) {
			UspellBook* theSpell = NewObject<UspellBook>();
			theSpell->myParticle = theParticle;
			theSpell->spellEffect = 0;
			theSpell->spellType = 0;
			theSpell->spellCost = 0.0;
			theSpell->spellSpeed = 0.0;
			theSpell->spellDamage = 0.5;
			theSpell->spellRange = 0.0;
			theSpell->spellSize = 0.0;
			theSpell->canBounce = false;
			theSpell->hasGravity = false;
			theSpell->isHoming = false;
			theSpell->explodeOnCollision = false;
			theSpell->explodeOnDeath = false;
			theSpell->explosionHitDamage = 0.5;
			theSpell->explosionHitSize = 0.0;
			theSpell->explosionDeathDamage = 0.5;
			theSpell->explosionDeathSize = 0.0;
			spellList.Add(theSpell);
		}
	}
else {
		spellList = LoadGameInstance->spellBook;
	}
}


//Saves the spells
void UWizardMenuWidget::spellsSave() {
	UWizardsSaveGame* SaveGameInstance = NewObject<UWizardsSaveGame>();
	SaveGameInstance->spellBook = spellList;
	SaveGameInstance->SaveGameDataToFile();
}

//Called when spell is changed in spell bar
//Changes all values to this spells values
void UWizardMenuWidget::spellChange(int32 spellSlot) {
	currSpell = spellSlot;
}

//List of all setters
UFUNCTION(BlueprintCallable, Category = "CustomSpells")
void UWizardMenuWidget::setEffect(int effectChange) {
	spellList[currSpell]->spellEffect = abs((spellList[currSpell]->spellEffect + effectChange)%5);// %however many spell types we have
}

void UWizardMenuWidget::setType(int typeChange) {
	spellList[currSpell]->spellType = abs((spellList[currSpell]->spellType + typeChange) % 3);// %however many spell types we have
}

void UWizardMenuWidget::setGravity(bool hasGravity) {
	spellList[currSpell]->hasGravity = hasGravity;
}

void UWizardMenuWidget::setBounce(bool hasBounce) {
	spellList[currSpell]->canBounce = hasBounce;
}

void UWizardMenuWidget::setHoming(bool isHoming) {
	spellList[currSpell]->isHoming = isHoming;
}

void UWizardMenuWidget::setExplodeHit(bool explodeHit) {
	spellList[currSpell]->explodeOnCollision = explodeHit;
}

void UWizardMenuWidget::setExplodeDeath(bool explodeDeath) {
	spellList[currSpell]->explodeOnDeath = explodeDeath;
}

void UWizardMenuWidget::setDamage(float damage) {
	spellList[currSpell]->spellDamage = damage;
}

void UWizardMenuWidget::setSpeed(float speed) {
	spellList[currSpell]->spellSpeed = speed;
}

void UWizardMenuWidget::setRange(float life) {
	spellList[currSpell]->spellRange = life;
}

void UWizardMenuWidget::setSize(float size) {
	spellList[currSpell]->spellSize = size;
}

void UWizardMenuWidget::setCost(float cost) {
	spellList[currSpell]->spellCost = cost;
}

void UWizardMenuWidget::setExplHitDamage(float damage) {
	spellList[currSpell]->explosionHitDamage = damage;
}

void UWizardMenuWidget::setExplHitSize(float size) {
	spellList[currSpell]->explosionHitSize = size;
}

void UWizardMenuWidget::setExplDeathDamage(float damage) {
	spellList[currSpell]->explosionDeathDamage = damage;
}

void UWizardMenuWidget::setExplDeathSize(float size) {
	spellList[currSpell]->explosionDeathSize = size;
}


//List of all getters

FName UWizardMenuWidget::getEffect() {
	FName returnName;
	switch (spellList[currSpell]->spellEffect)
	{
	case 0:
		returnName = "Fire";
		break;
	case 1:
		returnName = "Lightning";
		break;
	case 2:
		returnName = "Water";
		break;
	case 3:
		returnName = "Ice";
		break;
	case 4:
		returnName = "Earth";
		break;
	default:
		spellList[currSpell]->spellEffect = 0;
		returnName = "Fire";
		break;
	}
	return returnName;
}

FName UWizardMenuWidget::getType() {
	FName returnName;
	switch (spellList[currSpell]->spellType)
	{
	case 0:
		returnName = "Projectile";
		break;
	case 1:
		returnName = "Blast";
		break;
	case 2:
		returnName = "Cone";
		break;
	default:
		spellList[currSpell]->spellType = 0;
		returnName = "Projectile";
		break;
	}
	return returnName;
}

bool UWizardMenuWidget::getGravity() {
	return spellList[currSpell]->hasGravity;
}

bool UWizardMenuWidget::getBounce() {
	return spellList[currSpell]->canBounce;
}

bool UWizardMenuWidget::getHoming() {
	return spellList[currSpell]->isHoming;
}

bool UWizardMenuWidget::getExplodeHit() {
	return spellList[currSpell]->explodeOnCollision;
}

bool UWizardMenuWidget::getExplodeDeath() {
	return spellList[currSpell]->explodeOnDeath;
}

float UWizardMenuWidget::getDamage() {
	return spellList[currSpell]->spellDamage;
}

float UWizardMenuWidget::getSpeed() {
	return spellList[currSpell]->spellSpeed;
}

float UWizardMenuWidget::getRange() {
	return spellList[currSpell]->spellRange;
}

float UWizardMenuWidget::getSize() {
	return spellList[currSpell]->spellSize;
}

float UWizardMenuWidget::getCost() {
	return spellList[currSpell]->spellCost;
}

float UWizardMenuWidget::getExplHitDamage() {
	return spellList[currSpell]->explosionHitDamage;
}

float UWizardMenuWidget::getExplHitSize() {
	return spellList[currSpell]->explosionHitSize;
}

float UWizardMenuWidget::getExplDeathDamage() {
	return spellList[currSpell]->explosionDeathDamage;
}

float UWizardMenuWidget::getExplDeathSize() {
	return spellList[currSpell]->explosionDeathSize;
}
