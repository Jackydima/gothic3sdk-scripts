#pragma once

#include "../m_commandhandler.h"

namespace CMD_Tools_Sub
{
bCString ClearGameEvent(bTObjArray<bCString> a_arrParams);
bCString GameEventAC(bTObjArray<bCString> a_arrParams);
bCString SetGameEvent(bTObjArray<bCString> a_arrParams);
bCString IsSetGameEvent(bTObjArray<bCString> a_arrParams);
} // namespace CMD_Tools_Sub
