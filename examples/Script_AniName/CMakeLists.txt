add_library(Script_AniName SHARED)

target_link_libraries(Script_AniName PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_AniName)

target_tree_sources(Script_AniName
  PRIVATE
    Script_AniName.cpp
)
