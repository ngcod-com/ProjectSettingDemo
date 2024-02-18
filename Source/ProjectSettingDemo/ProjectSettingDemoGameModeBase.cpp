// Copyright Epic Games, Inc. All Rights Reserved.


#include "ProjectSettingDemoGameModeBase.h"

int32 AProjectSettingDemoGameModeBase::GetRemotePort()
{
	int32 LiveLinkPort = 0;
	GConfig->GetInt(TEXT("/Script/NLiveLink.NLiveLinkSettings"), TEXT("RemotePort"), LiveLinkPort, GEngineIni);
	return LiveLinkPort;
}
