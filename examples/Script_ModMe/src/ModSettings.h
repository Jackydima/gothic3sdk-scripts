#pragma once

#include <g3sdk/SharedBase.h>

struct mSModSettings
{
    GEBool Game_AutoStart;
    GEBool Game_HideTips;

    GEBool Logging_ModMe;
    GEBool Logging_Gothic;
};

mSModSettings const &GetModSettings();
