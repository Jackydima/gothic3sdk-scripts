#pragma once
#include <g3sdk/Script.h>
#include <g3sdk/util/Hook.h>
#include <g3sdk/util/Logging.h>
#include <g3sdk/util/Memory.h>
#include <g3sdk/util/Module.h>

#include <iostream>

extern "C" __declspec(dllexport) gSScriptInit const *GE_STDCALL ScriptInit(void);
