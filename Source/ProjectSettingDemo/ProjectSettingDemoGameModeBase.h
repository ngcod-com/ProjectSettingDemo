// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectSettingDemoGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTSETTINGDEMO_API AProjectSettingDemoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	int32 GetRemotePort();
};
