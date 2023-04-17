// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ResolveGUIDMaterialsStyle.h"

class FResolveGUIDMaterialsCommands : public TCommands<FResolveGUIDMaterialsCommands>
{
public:

	FResolveGUIDMaterialsCommands()
		: TCommands<FResolveGUIDMaterialsCommands>(TEXT("ResolveGUIDMaterials"), NSLOCTEXT("Contexts", "ResolveGUIDMaterials", "ResolveGUIDMaterials Plugin"), NAME_None, FResolveGUIDMaterialsStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
