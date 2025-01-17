// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WIZARDS_WizardMenuWidget_generated_h
#error "WizardMenuWidget.generated.h already included, missing '#pragma once' in WizardMenuWidget.h"
#endif
#define WIZARDS_WizardMenuWidget_generated_h

#define wizards_Source_Wizards_WizardMenuWidget_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execgetExplDeathSize) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getExplDeathSize(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplDeathDamage) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getExplDeathDamage(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplHitSize) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getExplHitSize(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplHitDamage) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getExplHitDamage(); \
	} \
 \
	DECLARE_FUNCTION(execgetCost) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getCost(); \
	} \
 \
	DECLARE_FUNCTION(execgetSize) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getSize(); \
	} \
 \
	DECLARE_FUNCTION(execgetRange) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getRange(); \
	} \
 \
	DECLARE_FUNCTION(execgetSpeed) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getSpeed(); \
	} \
 \
	DECLARE_FUNCTION(execgetDamage) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getDamage(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplodeDeath) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getExplodeDeath(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplodeHit) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getExplodeHit(); \
	} \
 \
	DECLARE_FUNCTION(execgetHoming) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getHoming(); \
	} \
 \
	DECLARE_FUNCTION(execgetBounce) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getBounce(); \
	} \
 \
	DECLARE_FUNCTION(execgetGravity) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getGravity(); \
	} \
 \
	DECLARE_FUNCTION(execgetType) \
	{ \
		P_FINISH; \
		*(FName*)Z_Param__Result=this->getType(); \
	} \
 \
	DECLARE_FUNCTION(execgetEffect) \
	{ \
		P_FINISH; \
		*(FName*)Z_Param__Result=this->getEffect(); \
	} \
 \
	DECLARE_FUNCTION(execsetExplDeathSize) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_size); \
		P_FINISH; \
		this->setExplDeathSize(Z_Param_size); \
	} \
 \
	DECLARE_FUNCTION(execsetExplDeathDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		this->setExplDeathDamage(Z_Param_damage); \
	} \
 \
	DECLARE_FUNCTION(execsetExplHitSize) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_size); \
		P_FINISH; \
		this->setExplHitSize(Z_Param_size); \
	} \
 \
	DECLARE_FUNCTION(execsetExplHitDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		this->setExplHitDamage(Z_Param_damage); \
	} \
 \
	DECLARE_FUNCTION(execsetCost) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_cost); \
		P_FINISH; \
		this->setCost(Z_Param_cost); \
	} \
 \
	DECLARE_FUNCTION(execsetSize) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_size); \
		P_FINISH; \
		this->setSize(Z_Param_size); \
	} \
 \
	DECLARE_FUNCTION(execsetRange) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_life); \
		P_FINISH; \
		this->setRange(Z_Param_life); \
	} \
 \
	DECLARE_FUNCTION(execsetSpeed) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_speed); \
		P_FINISH; \
		this->setSpeed(Z_Param_speed); \
	} \
 \
	DECLARE_FUNCTION(execsetDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		this->setDamage(Z_Param_damage); \
	} \
 \
	DECLARE_FUNCTION(execsetExplodeDeath) \
	{ \
		P_GET_UBOOL(Z_Param_explodeDeath); \
		P_FINISH; \
		this->setExplodeDeath(Z_Param_explodeDeath); \
	} \
 \
	DECLARE_FUNCTION(execsetExplodeHit) \
	{ \
		P_GET_UBOOL(Z_Param_explodeHit); \
		P_FINISH; \
		this->setExplodeHit(Z_Param_explodeHit); \
	} \
 \
	DECLARE_FUNCTION(execsetHoming) \
	{ \
		P_GET_UBOOL(Z_Param_isHoming); \
		P_FINISH; \
		this->setHoming(Z_Param_isHoming); \
	} \
 \
	DECLARE_FUNCTION(execsetBounce) \
	{ \
		P_GET_UBOOL(Z_Param_hasBounce); \
		P_FINISH; \
		this->setBounce(Z_Param_hasBounce); \
	} \
 \
	DECLARE_FUNCTION(execsetGravity) \
	{ \
		P_GET_UBOOL(Z_Param_hasGravity); \
		P_FINISH; \
		this->setGravity(Z_Param_hasGravity); \
	} \
 \
	DECLARE_FUNCTION(execspellChange) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_spellSlot); \
		P_FINISH; \
		this->spellChange(Z_Param_spellSlot); \
	} \
 \
	DECLARE_FUNCTION(execsetType) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_effectChange); \
		P_FINISH; \
		this->setType(Z_Param_effectChange); \
	} \
 \
	DECLARE_FUNCTION(execsetEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_effectChange); \
		P_FINISH; \
		this->setEffect(Z_Param_effectChange); \
	} \
 \
	DECLARE_FUNCTION(execspellsSave) \
	{ \
		P_FINISH; \
		this->spellsSave(); \
	} \
 \
	DECLARE_FUNCTION(execspellsInitialize) \
	{ \
		P_FINISH; \
		this->spellsInitialize(); \
	}


#define wizards_Source_Wizards_WizardMenuWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execgetExplDeathSize) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getExplDeathSize(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplDeathDamage) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getExplDeathDamage(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplHitSize) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getExplHitSize(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplHitDamage) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getExplHitDamage(); \
	} \
 \
	DECLARE_FUNCTION(execgetCost) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getCost(); \
	} \
 \
	DECLARE_FUNCTION(execgetSize) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getSize(); \
	} \
 \
	DECLARE_FUNCTION(execgetRange) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getRange(); \
	} \
 \
	DECLARE_FUNCTION(execgetSpeed) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getSpeed(); \
	} \
 \
	DECLARE_FUNCTION(execgetDamage) \
	{ \
		P_FINISH; \
		*(float*)Z_Param__Result=this->getDamage(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplodeDeath) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getExplodeDeath(); \
	} \
 \
	DECLARE_FUNCTION(execgetExplodeHit) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getExplodeHit(); \
	} \
 \
	DECLARE_FUNCTION(execgetHoming) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getHoming(); \
	} \
 \
	DECLARE_FUNCTION(execgetBounce) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getBounce(); \
	} \
 \
	DECLARE_FUNCTION(execgetGravity) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->getGravity(); \
	} \
 \
	DECLARE_FUNCTION(execgetType) \
	{ \
		P_FINISH; \
		*(FName*)Z_Param__Result=this->getType(); \
	} \
 \
	DECLARE_FUNCTION(execgetEffect) \
	{ \
		P_FINISH; \
		*(FName*)Z_Param__Result=this->getEffect(); \
	} \
 \
	DECLARE_FUNCTION(execsetExplDeathSize) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_size); \
		P_FINISH; \
		this->setExplDeathSize(Z_Param_size); \
	} \
 \
	DECLARE_FUNCTION(execsetExplDeathDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		this->setExplDeathDamage(Z_Param_damage); \
	} \
 \
	DECLARE_FUNCTION(execsetExplHitSize) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_size); \
		P_FINISH; \
		this->setExplHitSize(Z_Param_size); \
	} \
 \
	DECLARE_FUNCTION(execsetExplHitDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		this->setExplHitDamage(Z_Param_damage); \
	} \
 \
	DECLARE_FUNCTION(execsetCost) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_cost); \
		P_FINISH; \
		this->setCost(Z_Param_cost); \
	} \
 \
	DECLARE_FUNCTION(execsetSize) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_size); \
		P_FINISH; \
		this->setSize(Z_Param_size); \
	} \
 \
	DECLARE_FUNCTION(execsetRange) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_life); \
		P_FINISH; \
		this->setRange(Z_Param_life); \
	} \
 \
	DECLARE_FUNCTION(execsetSpeed) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_speed); \
		P_FINISH; \
		this->setSpeed(Z_Param_speed); \
	} \
 \
	DECLARE_FUNCTION(execsetDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_damage); \
		P_FINISH; \
		this->setDamage(Z_Param_damage); \
	} \
 \
	DECLARE_FUNCTION(execsetExplodeDeath) \
	{ \
		P_GET_UBOOL(Z_Param_explodeDeath); \
		P_FINISH; \
		this->setExplodeDeath(Z_Param_explodeDeath); \
	} \
 \
	DECLARE_FUNCTION(execsetExplodeHit) \
	{ \
		P_GET_UBOOL(Z_Param_explodeHit); \
		P_FINISH; \
		this->setExplodeHit(Z_Param_explodeHit); \
	} \
 \
	DECLARE_FUNCTION(execsetHoming) \
	{ \
		P_GET_UBOOL(Z_Param_isHoming); \
		P_FINISH; \
		this->setHoming(Z_Param_isHoming); \
	} \
 \
	DECLARE_FUNCTION(execsetBounce) \
	{ \
		P_GET_UBOOL(Z_Param_hasBounce); \
		P_FINISH; \
		this->setBounce(Z_Param_hasBounce); \
	} \
 \
	DECLARE_FUNCTION(execsetGravity) \
	{ \
		P_GET_UBOOL(Z_Param_hasGravity); \
		P_FINISH; \
		this->setGravity(Z_Param_hasGravity); \
	} \
 \
	DECLARE_FUNCTION(execspellChange) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_spellSlot); \
		P_FINISH; \
		this->spellChange(Z_Param_spellSlot); \
	} \
 \
	DECLARE_FUNCTION(execsetType) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_effectChange); \
		P_FINISH; \
		this->setType(Z_Param_effectChange); \
	} \
 \
	DECLARE_FUNCTION(execsetEffect) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_effectChange); \
		P_FINISH; \
		this->setEffect(Z_Param_effectChange); \
	} \
 \
	DECLARE_FUNCTION(execspellsSave) \
	{ \
		P_FINISH; \
		this->spellsSave(); \
	} \
 \
	DECLARE_FUNCTION(execspellsInitialize) \
	{ \
		P_FINISH; \
		this->spellsInitialize(); \
	}


#define wizards_Source_Wizards_WizardMenuWidget_h_17_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUWizardMenuWidget(); \
	friend WIZARDS_API class UClass* Z_Construct_UClass_UWizardMenuWidget(); \
	public: \
	DECLARE_CLASS(UWizardMenuWidget, UUserWidget, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Wizards"), NO_API) \
	DECLARE_SERIALIZER(UWizardMenuWidget) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define wizards_Source_Wizards_WizardMenuWidget_h_17_INCLASS \
	private: \
	static void StaticRegisterNativesUWizardMenuWidget(); \
	friend WIZARDS_API class UClass* Z_Construct_UClass_UWizardMenuWidget(); \
	public: \
	DECLARE_CLASS(UWizardMenuWidget, UUserWidget, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Wizards"), NO_API) \
	DECLARE_SERIALIZER(UWizardMenuWidget) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define wizards_Source_Wizards_WizardMenuWidget_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWizardMenuWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWizardMenuWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWizardMenuWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWizardMenuWidget); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UWizardMenuWidget(const UWizardMenuWidget& InCopy); \
public:


#define wizards_Source_Wizards_WizardMenuWidget_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWizardMenuWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UWizardMenuWidget(const UWizardMenuWidget& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWizardMenuWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWizardMenuWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWizardMenuWidget)


#define wizards_Source_Wizards_WizardMenuWidget_h_14_PROLOG
#define wizards_Source_Wizards_WizardMenuWidget_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	wizards_Source_Wizards_WizardMenuWidget_h_17_RPC_WRAPPERS \
	wizards_Source_Wizards_WizardMenuWidget_h_17_INCLASS \
	wizards_Source_Wizards_WizardMenuWidget_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define wizards_Source_Wizards_WizardMenuWidget_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	wizards_Source_Wizards_WizardMenuWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	wizards_Source_Wizards_WizardMenuWidget_h_17_INCLASS_NO_PURE_DECLS \
	wizards_Source_Wizards_WizardMenuWidget_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID wizards_Source_Wizards_WizardMenuWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
