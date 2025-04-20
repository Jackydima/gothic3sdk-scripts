#include "Tools_GameEvent.h"

#include <g3sdk/Script.h>
#include <g3sdk/util/Util.h>

bCString CMD_Tools_Sub::ClearGameEvent(bTObjArray<bCString> a_arrParams)
{
    Entity player = Entity::GetPlayer();

    bTObjArray<bCString> Result;
    bTObjArray<bCString> arrGameEvents = SplitString(a_arrParams[0], ";");
    for (GEInt i = 0; i < arrGameEvents.GetCount(); i++)
    {
        bCString const &strGameEvent = arrGameEvents[i];
        if (!player.PlayerMemory.IsSetGameEvent(strGameEvent))
        {
            Result.Add(bCString::GetFormattedString("%s was not set.", strGameEvent.GetText()));
        }
        else if (player.PlayerMemory.ClearGameEvent(strGameEvent))
        {
            Result.Add(bCString::GetFormattedString("%s has been cleared.", strGameEvent.GetText()));
        }
        else
        {
            return bCString::GetFormattedString("$Could not clear %s.", strGameEvent.GetText());
        }
    }

    return JoinString(Result, 0, "\n");
}

bCString CMD_Tools_Sub::GameEventAC(bTObjArray<bCString> a_arrParams)
{
    eCEntity const *pPlayer = gCSession::GetInstance().GetPlayer();
    if (pPlayer == 0)
        return JoinString(a_arrParams);

    gCPlayerMemory_PS const *pPlayerMemory = GetPropertySet<gCPlayerMemory_PS>(pPlayer, eEPropertySetType_PlayerMemory);
    if (pPlayerMemory == 0)
        return JoinString(a_arrParams);

    bTObjArray<bCString> const &arrGameEvents = pPlayerMemory->GetPlayerKnows();
    AutoCompleteString(arrGameEvents, a_arrParams[0], mCCommandHandler::GetInstance().IsAutoCompleteBackward());

    return JoinString(a_arrParams);
}

bCString CMD_Tools_Sub::SetGameEvent(bTObjArray<bCString> a_arrParams)
{
    Entity player = Entity::GetPlayer();

    bTObjArray<bCString> Result;
    bTObjArray<bCString> arrGameEvents = SplitString(a_arrParams[0], ";");
    for (GEInt i = 0; i < arrGameEvents.GetCount(); i++)
    {
        bCString const &strGameEvent = arrGameEvents[i];
        if (player.PlayerMemory.IsSetGameEvent(strGameEvent))
        {
            Result.Add(bCString::GetFormattedString("%s was already set.", strGameEvent.GetText()));
        }
        else if (player.PlayerMemory.SetGameEvent(strGameEvent))
        {
            Result.Add(bCString::GetFormattedString("%s has been set.", strGameEvent.GetText()));
        }
        else
        {
            return bCString::GetFormattedString("$Could not set %s.", strGameEvent.GetText());
        }
    }

    return JoinString(Result, 0, "\n");
}

bCString CMD_Tools_Sub::IsSetGameEvent(bTObjArray<bCString> a_arrParams)
{
    Entity player = Entity::GetPlayer();

    bTObjArray<bCString> Result;
    bTObjArray<bCString> arrGameEvents = SplitString(a_arrParams[0], ";");
    for (GEInt i = 0; i < arrGameEvents.GetCount(); i++)
    {
        bCString const &strGameEvent = arrGameEvents[i];
        if (player.PlayerMemory.IsSetGameEvent(strGameEvent))
            Result.Add(bCString::GetFormattedString("%s is set.", strGameEvent.GetText()));
        else
            Result.Add(bCString::GetFormattedString("%s is not set.", strGameEvent.GetText()));
    }

    return JoinString(Result, 0, "\n");
}
