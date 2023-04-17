// Copyright Epic Games, Inc. All Rights Reserved.

#include "ResolveGUIDMaterialsCommands.h"

#define LOCTEXT_NAMESPACE "FResolveGUIDMaterialsModule"

void FResolveGUIDMaterialsCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "ResolveGUIDMaterials", "Execute ResolveGUIDMaterials action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
