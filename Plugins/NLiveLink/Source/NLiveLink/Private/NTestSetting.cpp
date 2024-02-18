// Fill out your copyright notice in the Description page of Project Settings.


#include "NTestSetting.h"

bool UNTestSetting::Exec(UWorld* World, const TCHAR* Cmd, FOutputDevice& Ar)
{
	return FSelfRegisteringExec::Exec(World, Cmd, Ar);
}
