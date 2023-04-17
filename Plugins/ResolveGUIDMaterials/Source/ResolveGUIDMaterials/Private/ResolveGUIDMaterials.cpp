// Copyright Epic Games, Inc. All Rights Reserved.

#include "ResolveGUIDMaterials.h"
#include "ResolveGUIDMaterialsStyle.h"
#include "ResolveGUIDMaterialsCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName ResolveGUIDMaterialsTabName("ResolveGUIDMaterials");

#define LOCTEXT_NAMESPACE "FResolveGUIDMaterialsModule"

void FResolveGUIDMaterialsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FResolveGUIDMaterialsStyle::Initialize();
	FResolveGUIDMaterialsStyle::ReloadTextures();

	FResolveGUIDMaterialsCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FResolveGUIDMaterialsCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FResolveGUIDMaterialsModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FResolveGUIDMaterialsModule::RegisterMenus));
}

void FResolveGUIDMaterialsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FResolveGUIDMaterialsStyle::Shutdown();

	FResolveGUIDMaterialsCommands::Unregister();
}

void FResolveGUIDMaterialsModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FResolveGUIDMaterialsModule::PluginButtonClicked()")),
							FText::FromString(TEXT("ResolveGUIDMaterials.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FResolveGUIDMaterialsModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FResolveGUIDMaterialsCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FResolveGUIDMaterialsCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FResolveGUIDMaterialsModule, ResolveGUIDMaterials)