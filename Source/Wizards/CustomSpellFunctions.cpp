// Fill out your copyright notice in the Description page of Project Settings.

#include "Wizards.h"
#include "CustomSpellFunctions.h"

int32 UCustomSpellFunctions::MostDefinitelyaTest() {
	return 0;

}

//Initialize with previous values or defaults if nothing present
void UCustomSpellFunctions::spellsInitialize(){


}

//Saves the spells
void UCustomSpellFunctions::spellsSave(){

}

//Called when spell is changed in spell bar
//Changes all values to this spells values
void UCustomSpellFunctions::spellChange(int32 spellSlot){
	currSpell = spellSlot;
}

//List of all setters
void UCustomSpellFunctions::setGravity(bool hasGravity){
	spellList[currSpell].hasGravity = hasGravity;
}

void UCustomSpellFunctions::setBounce(bool hasBounce){
	spellList[currSpell].canBounce = hasBounce;
}

void UCustomSpellFunctions::setHoming(bool isHoming){
	spellList[currSpell].isHoming = isHoming;
}

void UCustomSpellFunctions::setExplodeHit(bool explodeHit){
	spellList[currSpell].explodeOnCollision = explodeHit;
}

void UCustomSpellFunctions::setExplodeDeath(bool explodeDeath){
	spellList[currSpell].explodeOnDeath = explodeDeath;
}

void UCustomSpellFunctions::setDamage(float damage){
	spellList[currSpell].spellDamage = damage;
}

void UCustomSpellFunctions::setSpeed(float speed){
	spellList[currSpell].spellSpeed = speed;
}

void UCustomSpellFunctions::setRange(float life){
	spellList[currSpell].spellRange = life;
}

void UCustomSpellFunctions::setSize(float size){
	spellList[currSpell].spellSize = size;


void UCustomSpellFunctions::setCost(float cost){
	spellList[currSpell].spellCost = cost;
}

void UCustomSpellFunctions::setExplHitDamage(float damage){
	spellList[currSpell].explodeHitDamage = damage;
}

void UCustomSpellFunctions::setExplHitSize(float size){
	spellList[currSpell].explodeHitSize = size;
}

void UCustomSpellFunctions::setExplDeathDamage(float damage){
	spellList[currSpell].explodeDeathDamage = damage;
}

void UCustomSpellFunctions::setExplDeathSize(float size){
	spellList[currSpell].explodeDeathSize = size;
}


//List of all getters

bool UCustomSpellFunctions::getGravity(){
	return spellList[currSpell].hasGravity;
}

bool UCustomSpellFunctions::getBounce(){
	return spellList[currSpell].canBounce;
}

bool UCustomSpellFunctions::getHoming(){
	return spellList[currSpell].isHoming;
}

bool UCustomSpellFunctions::getExplodeHit(){
	return spellList[currSpell].explodeOnCollision;
}

bool UCustomSpellFunctions::getExplodeDeath(){
	return spellList[currSpell].explodeOnDeath;
}

float UCustomSpellFunctions::getDamage(){
	return spellList[currSpell].spellDamage;
}

float UCustomSpellFunctions::getSpeed(){
	return spellList[currSpell].spellSpeed;
}

float UCustomSpellFunctions::getRange(){
	return spellList[currSpell].spellRange;
}

float UCustomSpellFunctions::getSize(){
	return spellList[currSpell].spellSize;
}

float UCustomSpellFunctions::getCost(){
	return spellList[currSpell].spellCost;
}

float UCustomSpellFunctions::getExplHitDamage(){
	return spellList[currSpell].explosiionHitDamage;
}

float UCustomSpellFunctions::getExplHitSize(){
	return spellList[currSpell].explosiionHitSize;
}

float UCustomSpellFunctions::getExplDeathDamage(){
	return spellList[currSpell].explosiionDeathDamage;
}

float UCustomSpellFunctions::getExplDeathSize(){
	return spellList[currSpell].explosiionDeathSize;
}

