// Copyright Epic Games, Inc. All Rights Reserved.

#include "ResolveGUIDMaterialsStyle.h"
#include "ResolveGUIDMaterials.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FResolveGUIDMaterialsStyle::StyleInstance = nullptr;

void FResolveGUIDMaterialsStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FResolveGUIDMaterialsStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FResolveGUIDMaterialsStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("ResolveGUIDMaterialsStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FResolveGUIDMaterialsStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("ResolveGUIDMaterialsStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("ResolveGUIDMaterials")->GetBaseDir() / TEXT("Resources"));

	Style->Set("ResolveGUIDMaterials.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));
	return Style;
}

void FResolveGUIDMaterialsStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FResolveGUIDMaterialsStyle::Get()
{
	return *StyleInstance;
}
