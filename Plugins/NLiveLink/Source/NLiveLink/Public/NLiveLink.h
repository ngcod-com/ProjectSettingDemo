// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FNLiveLinkModule : public IModuleInterface
{
public:
	FNLiveLinkModule()
		: ModularFeature(nullptr)
	{
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void PreExit();
private:
	IModularFeature* ModularFeature;
public:
#if WITH_EDITOR
	void PostEngineInit();
	void RegisterSettings();
	void UnregisterSettings();
#endif
};
