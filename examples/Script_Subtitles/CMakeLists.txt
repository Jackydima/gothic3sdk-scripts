add_library(Script_Subtitles SHARED)

target_link_libraries(Script_Subtitles PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_Subtitles)

target_tree_sources(Script_Subtitles
  PRIVATE
    Script_Subtitles.cpp
)
