// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Wizards.h"
#include "WizardsHUD.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "WizardsCharacter.h"
#include "text.h"

AWizardsHUD::AWizardsHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshiarTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshiarTexObj.Object;
	// Get the Wizard that is the owner of the HUD
	TheWizard = Cast<AWizardsCharacter>(UGameplayStatics::GetPlayerPawn(this,0));
	
	// Get the font for my evil experiment
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = HUDFontOb.Object;
}


void AWizardsHUD::DrawHUD()
{
	Super::DrawHUD();
	// Draw very simple crosshair
	if(TheWizard != NULL){
	float gottenHealth = TheWizard->GetHealth();
	float gottenMana = TheWizard->GetMana();
	int level = TheWizard->level;
	float exp = TheWizard->ExperienceNeededForNextLevel();
	FNumberFormattingOptions NumberFormat;
	NumberFormat.MinimumIntegralDigits = 1;
	NumberFormat.MaximumIntegralDigits = 10000;
	NumberFormat.MinimumFractionalDigits = 0;
	NumberFormat.MaximumFractionalDigits = 0;
    FString exp_formatted = FText::AsNumber(exp, &NumberFormat).ToString();
	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5)),
			   (Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)) );

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
	FString HealthString = FString::SanitizeFloat(gottenHealth);
	DrawText(HealthString, FColor::White, 50, 50, HUDFont);
	FString ManaString = FString::SanitizeFloat(gottenMana);
	DrawText(ManaString, FColor::White, 50, 100, HUDFont);
	FString LevelString = FString::FromInt(level);
	DrawText(LevelString, FColor::White, 50, 150, HUDFont);
	FString ExpString("Exp. needed for next level: ");
	ExpString.Append(exp_formatted);
	DrawText(ExpString, FColor::White, 50, 200, HUDFont);

}
else{
	//Do nothing
}
	

}

