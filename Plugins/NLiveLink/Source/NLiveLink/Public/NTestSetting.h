// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NTestSetting.generated.h"

/**
 * 
 */
UCLASS(Config=Game, defaultconfig)
class NLIVELINK_API UNTestSetting : public UObject, public FSelfRegisteringExec
{
	GENERATED_BODY()
public:
	//~ FSelfRegisteringExec
	virtual bool Exec(UWorld*, const TCHAR* Cmd, FOutputDevice& Ar) override;
	//~ FSelfRegisteringExec

	/** Where to write the curve files and image files */
	UPROPERTY(Config, BlueprintReadOnly, EditAnywhere, Category="UNTestSetting Settings", meta=(ToolTip="Target."))
	FString TargetName;
};
