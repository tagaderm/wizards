// Fill out your copyright notice in the Description page of Project Settings.

#include "Wizards.h"
#include "WizardMenuWidget.h"


//Initialize with previous values or defaults if nothing present
void UWizardMenuWidget::spellsInitialize() {
	UWizardsSaveGame* LoadGameInstance = Cast<UWizardsSaveGame>(UGameplayStatics::CreateSaveGameObject(UWizardsSaveGame::StaticClass()));
	LoadGameInstance = Cast<UWizardsSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->UserIndex));
	spellList = LoadGameInstance->spellList;
	//if is empty
	if (!spellList.IsValidIndex(0)) {
		//Initialize five spells
		for (int8 i = 0; i < 5; i++) {
			ConstructorHelpers::FObjectFinder<UParticleSystem> ArbitraryParticleName(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
			spellList[i].myParticle = ArbitraryParticleName.Object;
			spellList[i].spellType = 0;
			spellList[i].spellCost = 0.0;
			spellList[i].spellSpeed = 0.0;
			spellList[i].spellDamage = 0.0;
			spellList[i].spellRange = 0.0;
			spellList[i].spellSize = 0.0;
			bool canBounce = false;
			bool hasGravity = false;
			bool isHoming = false;
			bool explodeOnCollision = false;
			bool explodeOnDeath = false;
			float explosionHitDamage = 0.0;
			float explosionHitSize = 0.0;
			float explosionDeathDamage = 0.0;
			float explosionDeathSize = 0.0;
		}
	}
}


//Saves the spells
void UWizardMenuWidget::spellsSave() {

}

//Called when spell is changed in spell bar
//Changes all values to this spells values
void UWizardMenuWidget::spellChange(int32 spellSlot) {
	currSpell = spellSlot;
}

//List of all setters
void UWizardMenuWidget::setGravity(bool hasGravity) {
	spellList[currSpell].hasGravity = hasGravity;
}

void UWizardMenuWidget::setBounce(bool hasBounce) {
	spellList[currSpell].canBounce = hasBounce;
}

void UWizardMenuWidget::setHoming(bool isHoming) {
	spellList[currSpell].isHoming = isHoming;
}

void UWizardMenuWidget::setExplodeHit(bool explodeHit) {
	spellList[currSpell].explodeOnCollision = explodeHit;
}

void UWizardMenuWidget::setExplodeDeath(bool explodeDeath) {
	spellList[currSpell].explodeOnDeath = explodeDeath;
}

void UWizardMenuWidget::setDamage(float damage) {
	spellList[currSpell].spellDamage = damage;
}

void UWizardMenuWidget::setSpeed(float speed) {
	spellList[currSpell].spellSpeed = speed;
}

void UWizardMenuWidget::setRange(float life) {
	spellList[currSpell].spellRange = life;
}

void UWizardMenuWidget::setSize(float size) {
	spellList[currSpell].spellSize = size;
}

void UWizardMenuWidget::setCost(float cost) {
	spellList[currSpell].spellCost = cost;
}

void UWizardMenuWidget::setExplHitDamage(float damage) {
	spellList[currSpell].explosionHitDamage = damage;
}

void UWizardMenuWidget::setExplHitSize(float size) {
	spellList[currSpell].explosionHitSize = size;
}

void UWizardMenuWidget::setExplDeathDamage(float damage) {
	spellList[currSpell].explosionDeathDamage = damage;
}

void UWizardMenuWidget::setExplDeathSize(float size) {
	spellList[currSpell].explosionDeathSize = size;
}


//List of all getters

bool UWizardMenuWidget::getGravity() {
	return spellList[currSpell].hasGravity;
}

bool UWizardMenuWidget::getBounce() {
	return spellList[currSpell].canBounce;
}

bool UWizardMenuWidget::getHoming() {
	return spellList[currSpell].isHoming;
}

bool UWizardMenuWidget::getExplodeHit() {
	return spellList[currSpell].explodeOnCollision;
}

bool UWizardMenuWidget::getExplodeDeath() {
	return spellList[currSpell].explodeOnDeath;
}

float UWizardMenuWidget::getDamage() {
	return spellList[currSpell].spellDamage;
}

float UWizardMenuWidget::getSpeed() {
	return spellList[currSpell].spellSpeed;
}

float UWizardMenuWidget::getRange() {
	return spellList[currSpell].spellRange;
}

float UWizardMenuWidget::getSize() {
	return spellList[currSpell].spellSize;
}

float UWizardMenuWidget::getCost() {
	return spellList[currSpell].spellCost;
}

float UWizardMenuWidget::getExplHitDamage() {
	return spellList[currSpell].explosionHitDamage;
}

float UWizardMenuWidget::getExplHitSize() {
	return spellList[currSpell].explosionHitSize;
}

float UWizardMenuWidget::getExplDeathDamage() {
	return spellList[currSpell].explosionDeathDamage;
}

float UWizardMenuWidget::getExplDeathSize() {
	return spellList[currSpell].explosionDeathSize;
}
