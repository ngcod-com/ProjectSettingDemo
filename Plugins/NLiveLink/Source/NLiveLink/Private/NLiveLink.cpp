// Copyright Epic Games, Inc. All Rights Reserved.

#include "NLiveLink.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#endif
#include "NLiveLinkSettings.h"
#include "NTestSetting.h"

#define LOCTEXT_NAMESPACE "FNLiveLinkModule"

void FNLiveLinkModule::StartupModule()
{
	FCoreDelegates::OnPreExit.AddRaw(this, &FNLiveLinkModule::PreExit);

#if WITH_EDITOR
	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FNLiveLinkModule::PostEngineInit);
#endif
	
	bool bEnableLiveLinkForFaceTracking = false;
	GConfig->GetBool(TEXT("/Script/AppleARKit.AppleARKitSettings"), TEXT("bEnableLiveLinkForFaceTracking"), bEnableLiveLinkForFaceTracking, GEngineIni);
}

void FNLiveLinkModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FNLiveLinkModule::PreExit()
{
#if WITH_EDITOR
	UnregisterSettings();
#endif
}

#if WITH_EDITOR
void FNLiveLinkModule::PostEngineInit()
{
	RegisterSettings();
}

#define NLIVELINK_CATEGORY "Ngcod"
#define NLIVELINK_SECTION "NLiveLink"
#define NTest_SECTION "NTest"
void FNLiveLinkModule::RegisterSettings()
{
	{
		ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

		if (SettingsModule != nullptr)
		{
			SettingsModule->RegisterSettings("Project", NLIVELINK_CATEGORY, NLIVELINK_SECTION,
				LOCTEXT("NLiveLinkSettingsName", "NLiveLink Title"),//显示在Project Setting中的名字.
				LOCTEXT("NLiveLinkSettingsDescription", "Configure the NLiveLink plug-in."),
				GetMutableDefault<UNLiveLinkSettings>()
			);
			
			SettingsModule->RegisterSettings("Editor", NLIVELINK_CATEGORY, NTest_SECTION,
				LOCTEXT("NTestSettingsName", "TestSetting Title"),//显示在Project Setting中的名字.
				LOCTEXT("NTestSettingsDescription", "Configure the NTest plug-in."),
				GetMutableDefault<UNTestSetting>()
			);
		}
	}
}

void FNLiveLinkModule::UnregisterSettings()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule)
	{
		SettingsModule->UnregisterSettings("Project", NLIVELINK_CATEGORY, NLIVELINK_SECTION);
		SettingsModule->UnregisterSettings("Project", NLIVELINK_CATEGORY, NTest_SECTION);
	}
}
#endif

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNLiveLinkModule, NLiveLink)