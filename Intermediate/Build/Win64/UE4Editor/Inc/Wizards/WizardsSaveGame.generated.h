// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WIZARDS_WizardsSaveGame_generated_h
#error "WizardsSaveGame.generated.h already included, missing '#pragma once' in WizardsSaveGame.h"
#endif
#define WIZARDS_WizardsSaveGame_generated_h

#define wizards_Source_Wizards_WizardsSaveGame_h_21_RPC_WRAPPERS
#define wizards_Source_Wizards_WizardsSaveGame_h_21_RPC_WRAPPERS_NO_PURE_DECLS
#define wizards_Source_Wizards_WizardsSaveGame_h_21_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUWizardsSaveGame(); \
	friend WIZARDS_API class UClass* Z_Construct_UClass_UWizardsSaveGame(); \
	public: \
	DECLARE_CLASS(UWizardsSaveGame, USaveGame, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Wizards"), NO_API) \
	DECLARE_SERIALIZER(UWizardsSaveGame) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define wizards_Source_Wizards_WizardsSaveGame_h_21_INCLASS \
	private: \
	static void StaticRegisterNativesUWizardsSaveGame(); \
	friend WIZARDS_API class UClass* Z_Construct_UClass_UWizardsSaveGame(); \
	public: \
	DECLARE_CLASS(UWizardsSaveGame, USaveGame, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Wizards"), NO_API) \
	DECLARE_SERIALIZER(UWizardsSaveGame) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define wizards_Source_Wizards_WizardsSaveGame_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWizardsSaveGame(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWizardsSaveGame) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWizardsSaveGame); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWizardsSaveGame); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UWizardsSaveGame(const UWizardsSaveGame& InCopy); \
public:


#define wizards_Source_Wizards_WizardsSaveGame_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UWizardsSaveGame(const UWizardsSaveGame& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWizardsSaveGame); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWizardsSaveGame); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UWizardsSaveGame)


#define wizards_Source_Wizards_WizardsSaveGame_h_18_PROLOG
#define wizards_Source_Wizards_WizardsSaveGame_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	wizards_Source_Wizards_WizardsSaveGame_h_21_RPC_WRAPPERS \
	wizards_Source_Wizards_WizardsSaveGame_h_21_INCLASS \
	wizards_Source_Wizards_WizardsSaveGame_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define wizards_Source_Wizards_WizardsSaveGame_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	wizards_Source_Wizards_WizardsSaveGame_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	wizards_Source_Wizards_WizardsSaveGame_h_21_INCLASS_NO_PURE_DECLS \
	wizards_Source_Wizards_WizardsSaveGame_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID wizards_Source_Wizards_WizardsSaveGame_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
