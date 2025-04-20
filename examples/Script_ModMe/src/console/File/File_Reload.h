#pragma once

#include "../m_commandhandler.h"

namespace CMD_File_Sub
{
bCString Reload(bTObjArray<bCString> a_arrParams);
}

namespace File_Reload
{
typedef void (*mFReloadCallback)(void);
void RegisterReloadable(bCString a_strName, mFReloadCallback a_fCallback);
} // namespace File_Reload
