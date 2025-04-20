add_library(Script_AniName_Adp SHARED)

target_link_libraries(Script_AniName_Adp PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_AniName_Adp)

target_tree_sources(Script_AniName_Adp
  PRIVATE
    Script_AniName_Adp.cpp
)
