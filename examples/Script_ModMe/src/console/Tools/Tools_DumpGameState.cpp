#include "Tools_DumpGameState.h"

#include <g3sdk/Script.h>
#include <g3sdk/util/Logging.h>
#include <g3sdk/util/Util.h>

namespace
{
void DumpGameEvents(mCFileLogger &Logger)
{
    Logger.LogString("----- Set GameEvents -----\n");
    Logger.PushIndent();

    gCPlayerMemory_PS const *pPlayerMemory =
        GetPropertySet<gCPlayerMemory_PS>(GetPlayer(), eEPropertySetType_PlayerMemory);
    if (pPlayerMemory)
    {
        bTObjArray<bCString> const &arrGameEvents = pPlayerMemory->GetPlayerKnows();
        for (GEInt i = 0; i < arrGameEvents.GetCount(); i++)
            Logger.LogFormat("%s\n", arrGameEvents[i].GetText());
    }
    else
        Logger.LogString("Player entity has no gCPlayerMemory_PS property set.\n");

    Logger.PopIndent();
}

void DumpInfos(mCFileLogger &Logger)
{
    Logger.LogString("----- Infos -----\n");
    Logger.PushIndent();

    if (gCInfoManager_PS *pInfoManager = gCInfoManager_PS::GetInstance())
    {
        bTPtrArray<gCInfo_PS *> const &arrInfos = pInfoManager->GetInfos();
        for (GEInt i = 0; i < arrInfos.GetCount(); i++)
        {
            gCInfo_PS const *pInfo = arrInfos[i];
            Logger.LogFormat("%s: Executed = %s, Available = %s\n", pInfo->GetName().GetText(),
                             pInfo->IsPermanent() ? "Permanent" : BoolToString(pInfo->GetInfoGiven()).GetText(),
                             BoolToString(pInfo->IsAvailable()).GetText());
        }
    }
    else
        Logger.LogString("Unable to access InfoManager.\n");

    Logger.PopIndent();
}

void DumpQuests(mCFileLogger &Logger)
{
    Logger.LogString("----- Quests -----\n");
    Logger.PushIndent();

    if (gCQuestManager_PS *pQuestManager = gCQuestManager_PS::GetInstance())
    {
        bTObjArray<bTAutoPOSmartPtr<gCQuest_PS>> const &arrQuests = pQuestManager->GetQuests();
        for (GEInt i = 0; i < arrQuests.GetCount(); i++)
        {
            auto const &Quest = arrQuests[i];
            Logger.LogFormat("%s: Status = %s, LogTextCount = %d\n", Quest->GetName().GetText(),
                             ToString(Quest->GetStatus()).GetText(), Quest->GetLogText().GetCount());
        }
    }
    else
        Logger.LogString("Unable to access QuestManager.\n");

    Logger.PopIndent();
}
} // namespace

bCString CMD_Tools_Sub::DumpGameState(bTObjArray<bCString> a_arrParams)
{
    bCDateTime Time;
    Time.Update();
    bCString DumpFileName = "GameState__" + FormatDate(Time, "yyyy_MM_dd") + "_" + FormatTime(Time, "HH_mm_ss");

    mCFileLogger &Logger = mCFileLogger::GetInstance(DumpFileName);
    DumpGameEvents(Logger);
    Logger.LogString("\n\n");

    DumpInfos(Logger);
    Logger.LogString("\n\n");

    DumpQuests(Logger);
    mCLoggingAdmin<mCFileLogger>::FreeLogger(Logger);

    return bCString::GetFormattedString("Dumped game state to 'logs/%s.log'.", DumpFileName.GetText());
}
