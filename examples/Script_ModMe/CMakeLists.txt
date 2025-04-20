add_library(Script_ModMe SHARED)

target_link_libraries(Script_ModMe PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_ModMe)

target_include_directories(Script_ModMe PRIVATE src)

target_tree_sources(Script_ModMe
  BASE src
  PRIVATE
    Common.h
    ModSettings.h
    Script_ModMe.cpp

    console/m_commandhandler.cpp
    console/m_commandhandler.h
    console/Entity/Entity.cpp
    console/Entity/Entity.h
    console/Entity/Entity_Enable.cpp
    console/Entity/Entity_Enable.h
    console/Entity/Entity_Equip.cpp
    console/Entity/Entity_Equip.h
    console/Entity/Entity_Goto.cpp
    console/Entity/Entity_Goto.h
    console/Entity/Entity_LogInventory.cpp
    console/Entity/Entity_LogInventory.h
    console/File/File.cpp
    console/File/File.h
    console/File/File_ColMesh.cpp
    console/File/File_ColMesh.h
    console/File/File_Dump.cpp
    console/File/File_Dump.h
    console/File/File_Reload.cpp
    console/File/File_Reload.h
    console/Tools/Tools.cpp
    console/Tools/Tools.h
    console/Tools/Tools_DumpGameState.cpp
    console/Tools/Tools_DumpGameState.h
    console/Tools/Tools_GameEvent.cpp
    console/Tools/Tools_GameEvent.h
    console/Tools/Tools_Quest.cpp
    console/Tools/Tools_Quest.h
    console/Tools/Tools_SetStringtable.cpp
    console/Tools/Tools_SetStringtable.h
    console/Vars/Vars.cpp
    console/Vars/Vars.h
    console/World/World.cpp
    console/World/World.h
    console/World/World_CompileLightmaps.cpp
    console/World/World_CompileLightmaps.h
    console/World/World_SaveLayer.cpp
    console/World/World_SaveLayer.h
    console/World/World_SaveSector.cpp
    console/World/World_SaveSector.h

    mods/CollisionShape.cpp
    mods/DummyCollector.cpp
    mods/EasyStart.cpp
    mods/FixResourceAnimationActor.cpp
    mods/FixResourceMeshComplex.cpp
    mods/MessageLogger.cpp
    mods/ResourceCompiler.cpp
    mods/ResourceCompiler.h
)
