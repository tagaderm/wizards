// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WIZARDS_WizardsHUD_generated_h
#error "WizardsHUD.generated.h already included, missing '#pragma once' in WizardsHUD.h"
#endif
#define WIZARDS_WizardsHUD_generated_h

#define wizards_Source_Wizards_WizardsHUD_h_11_RPC_WRAPPERS
#define wizards_Source_Wizards_WizardsHUD_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define wizards_Source_Wizards_WizardsHUD_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAWizardsHUD(); \
	friend WIZARDS_API class UClass* Z_Construct_UClass_AWizardsHUD(); \
	public: \
	DECLARE_CLASS(AWizardsHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/Wizards"), NO_API) \
	DECLARE_SERIALIZER(AWizardsHUD) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define wizards_Source_Wizards_WizardsHUD_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAWizardsHUD(); \
	friend WIZARDS_API class UClass* Z_Construct_UClass_AWizardsHUD(); \
	public: \
	DECLARE_CLASS(AWizardsHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/Wizards"), NO_API) \
	DECLARE_SERIALIZER(AWizardsHUD) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define wizards_Source_Wizards_WizardsHUD_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWizardsHUD(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWizardsHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWizardsHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWizardsHUD); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AWizardsHUD(const AWizardsHUD& InCopy); \
public:


#define wizards_Source_Wizards_WizardsHUD_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API AWizardsHUD(const AWizardsHUD& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWizardsHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWizardsHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWizardsHUD)


#define wizards_Source_Wizards_WizardsHUD_h_8_PROLOG
#define wizards_Source_Wizards_WizardsHUD_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	wizards_Source_Wizards_WizardsHUD_h_11_RPC_WRAPPERS \
	wizards_Source_Wizards_WizardsHUD_h_11_INCLASS \
	wizards_Source_Wizards_WizardsHUD_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define wizards_Source_Wizards_WizardsHUD_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	wizards_Source_Wizards_WizardsHUD_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	wizards_Source_Wizards_WizardsHUD_h_11_INCLASS_NO_PURE_DECLS \
	wizards_Source_Wizards_WizardsHUD_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID wizards_Source_Wizards_WizardsHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
