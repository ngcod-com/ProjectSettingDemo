// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NLiveLinkSettings.generated.h"

/**
 * 
 */
UCLASS(Config=Engine, defaultconfig)
class NLIVELINK_API UNLiveLinkSettings : public UObject, public FSelfRegisteringExec
{
	GENERATED_BODY()
public:
	UNLiveLinkSettings();
	int32 GetRemotePort();
	FString GetRemoteURL();
protected:
	//~ FSelfRegisteringExec
	virtual bool Exec(UWorld*, const TCHAR* Cmd, FOutputDevice& Ar) override;
	//~ FSelfRegisteringExec

	/** Where to write the curve files and image files */
	UPROPERTY(Config, BlueprintReadOnly, EditAnywhere, Category="NLiveLink Settings A", meta=(ToolTip="Remote Server UDP Port."))
	int32 RemotePort;
    
	UPROPERTY(Config, BlueprintReadOnly, EditAnywhere, Category="NLiveLink Settings A", meta=(ToolTip="Remote Server URL."))
	FString RemoteUrl;

	UPROPERTY(Config, BlueprintReadOnly, EditAnywhere, Category="NLiveLink Settings B", meta=(ToolTip="reconnect time duration. the server lose"))
	int32 ReloginTime;
private:
	/** Used because these defaults need to be read on multiple threads */
	FCriticalSection CriticalSection;
};
