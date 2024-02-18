// Fill out your copyright notice in the Description page of Project Settings.


#include "NLiveLinkSettings.h"

UNLiveLinkSettings::UNLiveLinkSettings() : RemotePort(11113), RemoteUrl(TEXT("127.0.0.1")), ReloginTime(5000)
{
}

int32 UNLiveLinkSettings::GetRemotePort()
{
	FScopeLock ScopeLock(&CriticalSection);
	return RemotePort;
}

FString UNLiveLinkSettings::GetRemoteURL()
{
	FScopeLock ScopeLock(&CriticalSection);
	return RemoteUrl;
}

bool UNLiveLinkSettings::Exec(UWorld* World, const TCHAR* Cmd, FOutputDevice& Ar)
{
	if (FParse::Command(&Cmd, TEXT("ARKitSettings")))
	{
		FScopeLock ScopeLock(&CriticalSection);
	}
	return false;
}
