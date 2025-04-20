#include "Entity_Goto.h"

#include <g3sdk/Script.h>
#include <g3sdk/util/Util.h>

bCString CMD_Entity_Sub::Goto(bTObjArray<bCString> a_arrParams)
{
    // Zweimal nacheinander zur selben Position geht nicht
    eCEntity *pPlayer = gCSession::GetInstance().GetPlayer();

    gCCharacterMovement_PS *pCharMovement =
        GetPropertySet<gCCharacterMovement_PS>(pPlayer, eEPropertySetType_CharacterMovement);
    gCScriptRoutine_PS *pScriptRoutine = GetPropertySet<gCScriptRoutine_PS>(pPlayer, eEPropertySetType_ScriptRoutine);
    gCNavigation_PS *pNavigation = GetPropertySet<gCNavigation_PS>(pPlayer, eEPropertySetType_Navigation);

    pCharMovement->SetMovementMode(static_cast<gECharMovementMode>(3));
    pScriptRoutine->AIFullStop();
    pScriptRoutine->SetCurrentTask("ZS_NavEval");
    pScriptRoutine->SetCurrentState("ZS_NavEval");
    pNavigation->Reset(GEFalse, GETrue, GETrue);

    bCMotion Destination;
    Destination.m_Position.SetX(a_arrParams[0].GetFloat(0));
    Destination.m_Position.SetY(a_arrParams[1].GetFloat(0));
    Destination.m_Position.SetZ(a_arrParams[2].GetFloat(0));
    Destination.m_Rotation = bCMatrix3::GetIdentity();
    pNavigation->AccessDestination().Add(Destination);

    return bCString::GetFormattedString("Player is going to %s/%s/%s.", a_arrParams[0].GetText(),
                                        a_arrParams[1].GetText(), a_arrParams[2].GetText());
}
